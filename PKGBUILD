# Maintainer: Egon Dogo <borissopko5@gmail.com>
pkgname='peckel'
pkgver=r103.7d0783c
pkgrel=1
pkgdesc="some anoying guy"
arch=('x86_64')
url="https://github.com/BeanLover69/peckel"
license=('GPL')
depends=('glib2' 'glibc' 'zlib' 'libutil-linux' 'libffi' 'pcre' 'libx11')
makedepends=('git')
source=('peckel::git+https://github.com/BeanLover69/peckel')
md5sums=('SKIP')

pkgver() {
  cd "$pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
}

build() {
	cd "$pkgname"
	make
}

package() {
	cd "$pkgname"
	install -Dm 775 peckel "$pkgdir/usr/bin/peckel"
	install -Dm 644 README.md "$pkgdir/usr/share/doc/$pkgname"
	install -Dm 644 peckel.png "$pkgdir/usr/share/icons/hicolor/32x32/apps/peckel.png"
	install -Dm 644 peckel.png "$pkgdir/opt/peckel/peckel.png"
	install -Dm 644 peckel_sad.png "$pkgdir/opt/peckel/peckel_sad.png"
	install -Dm 644 peckel_tired.png "$pkgdir/opt/peckel/peckel_tired.png"
	install -Dm 644 peckel_happy.png "$pkgdir/opt/peckel/peckel_happy.png"
	install -Dm 644 peckel.desktop "$pkgdir/usr/share/applications/peckel.desktop"
}
