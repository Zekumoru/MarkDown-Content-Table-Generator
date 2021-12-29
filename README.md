# MarkDown-Content-Table-Generator
## Description
Suppliying a .md file to this program generates another .md file which contains the table of contents of the specified .md file. It generates the table of contents using headers (h1-h6, or in markdown, # to ######)

Made by Zekumoru.\
Latest version: 0.1.211229

## Usage
### Opening the help section
```
md-ctable-gen --help
```

or

```
md-ctable-gen -h
```

### Generate using file
```
md-ctable-gen <filename>
```

Generates .md containing table of contents for `<filename>`.\
It starts and does not ignore header level 1 or `#`.

> When providing `<filename>`, do not forget to also provide the `.md` extension.

### Generate using file and header level
```
md-ctable-gen <filename> <headerLevel>
```

Generates .md containing table of contents for `<filename>`.\
It ignores header levels that are lower than the specified `<headerLevel>`

> `<headerLevel>` accepts as input an integer between 1 and 6.

## Example
The following block of code will be used to generate its table of contents.\
Let's say it has the file name `test.md`.

```
# Header Lv1
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc sagittis pretium feugiat. Suspendisse porttitor mauris non libero rutrum, ac suscipit mauris rhoncus.

## Header Lv2 - Hello!
Fusce sem urna, semper sit amet consequat nec, suscipit rutrum odio.

### Header Lv3
Phasellus rutrum arcu vitae felis maximus bibendum. Quisque semper accumsan tellus. Proin pulvinar ex nisl, a feugiat erat feugiat et.

### Header Lv3
Etiam interdum accumsan placerat. Donec et nisl tincidunt, ornare mauris et, malesuada odio.

## Header Lv2 - Another one
Aenean egestas suscipit magna. Donec blandit eu diam sed pellentesque. Duis efficitur, risus at sodales luctus, tortor ligula dignissim augue, in laoreet libero nibh ac lorem.

### Header lv3 inside the other header 2
Vivamus ut turpis blandit sapien faucibus hendrerit.

# Another Major Header
Donec pulvinar volutpat velit quis imperdiet. Quisque et est nec purus bibendum eleifend sed ac tellus. Phasellus porta scelerisque mauris ac pulvinar.
```

### Generating the table providing only the file
```
md-ctable-gen test.md
```

Inside the output file
```
[Header Lv1](#header-lv1)
  - [Header Lv2 - Hello!](#header-lv2---hello)
    - [Header Lv3](#header-lv3)
    - [Header Lv3](#header-lv3-1)
  - [Header Lv2 - Another one](#header-lv2---another-one)
    - [Header lv3 inside the other header 2](#header-lv3-inside-the-other-header-2)
[Another Major Header](#another-major-header)
```

> Notice that the default header level is 1.\
> Check the second example below to understand better what header level means.

### Generating the table providing the file and a header level
Let's provide 2 as the header level.

```
md-ctable-gen test.md 2
```

Inside the output file
```
[Header Lv2 - Hello!](#header-lv2---hello)
  - [Header Lv3](#header-lv3)
  - [Header Lv3](#header-lv3-1)
[Header Lv2 - Another one](#header-lv2---another-one)
  - [Header lv3 inside the other header 2](#header-lv3-inside-the-other-header-2)
```

Notice that the header levels less than 2 are ignored.

## Logs
### version 0.1.211229b
- Fixed headers without bullets bug

### version 0.1.211229
- Initial release
