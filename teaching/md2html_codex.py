import re
from pathlib import Path

teaching_dir = Path(r"c:\Users\Spane\Desktop\c-course\Henry-s-c-course-lab-neo\teaching")
md_path = None
for p in teaching_dir.glob("*codex.md"):
    if "算法清单" in p.name:
        md_path = p
        break

if md_path is None:
    raise SystemExit("not_found")

html_path = teaching_dir / "算法清单_仓库算法总览codex.html"

text = md_path.read_text(encoding="utf-8").splitlines()

def inline_format(s: str) -> str:
    s = s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")
    s = re.sub(r"\*\*(.+?)\*\*", r"<strong>\1</strong>", s)
    s = re.sub(r"`([^`]+)`", r"<code>\1</code>", s)
    return s

html_lines = []
in_ul = False
in_ol = False

for raw in text:
    line = raw.rstrip()
    if not line.strip():
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        continue

    if line.startswith("# "):
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        html_lines.append(f"<h1>{inline_format(line[2:])}</h1>")
        continue

    if line.startswith("## "):
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        html_lines.append(f"<h2>{inline_format(line[3:])}</h2>")
        continue

    if line.startswith("### "):
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        html_lines.append(f"<h3>{inline_format(line[4:])}</h3>")
        continue

    if line.startswith("> "):
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        html_lines.append(f"<blockquote>{inline_format(line[2:])}</blockquote>")
        continue

    if line.startswith("- "):
        if in_ol:
            html_lines.append("</ol>")
            in_ol = False
        if not in_ul:
            html_lines.append("<ul>")
            in_ul = True
        html_lines.append(f"<li>{inline_format(line[2:])}</li>")
        continue

    if re.match(r"^\d+\)\s+", line):
        if in_ul:
            html_lines.append("</ul>")
            in_ul = False
        if not in_ol:
            html_lines.append("<ol>")
            in_ol = True
        item = re.sub(r"^\d+\)\s+", "", line)
        html_lines.append(f"<li>{inline_format(item)}</li>")
        continue

    if in_ul:
        html_lines.append("</ul>")
        in_ul = False
    if in_ol:
        html_lines.append("</ol>")
        in_ol = False
    html_lines.append(f"<p>{inline_format(line)}</p>")

if in_ul:
    html_lines.append("</ul>")
if in_ol:
    html_lines.append("</ol>")

html = """<!doctype html>
<html lang=\"zh-CN\">
<head>
<meta charset=\"utf-8\">
<title>仓库算法清单讲义</title>
<style>
  :root { --text: #1b1f23; --muted: #6a737d; --bg: #ffffff; --accent: #0b6fa4; }
  body { font-family: "Segoe UI", "Microsoft YaHei", "PingFang SC", sans-serif; color: var(--text); background: var(--bg); margin: 40px; line-height: 1.6; }
  h1 { font-size: 26px; border-bottom: 2px solid #e5e5e5; padding-bottom: 8px; }
  h2 { font-size: 20px; margin-top: 26px; color: var(--accent); }
  h3 { font-size: 16px; margin-top: 18px; }
  p { margin: 8px 0; }
  ul, ol { margin: 6px 0 12px 22px; }
  li { margin: 4px 0; }
  blockquote { margin: 12px 0; padding: 8px 12px; background: #f5f7f9; border-left: 4px solid var(--accent); color: var(--muted); }
  code { font-family: Consolas, "Courier New", monospace; background: #f0f2f4; padding: 0 4px; border-radius: 3px; }
</style>
</head>
<body>
""" + "\n".join(html_lines) + "\n</body>\n</html>"

html_path.write_text(html, encoding="utf-8")
print(str(html_path))
