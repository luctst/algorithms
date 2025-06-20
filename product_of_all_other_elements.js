// Given an array of integers, return a nnew array such thet each elemant at index i of the new array is the product of all the numbers in the original array except the one at i

function products(array) {
	const prefix_products = []
	let suffix_products = []
	const result = []

	for (let i = 0; i < array.length; i++) {
		if (prefix_products.length) {
			prefix_products.push(prefix_products[prefix_products.length - 1] * array[i])
		} else {
			prefix_products.push(array[i])
		}
	}

	for (let i = 0; i < array.length; i++) {
		if (suffix_products.length) {
			suffix_products.push(suffix_products[suffix_products.length - 1] * array.reverse()[i])
		} else {
			suffix_products.push(array.reverse()[i])
		}
	}
	suffix_products = suffix_products.reverse()

	for (let i = 0; i < array.length; i++) {
		if (i === 0) {
			result.push(suffix_products[i + 1])
		} else if (i === array.length - 1) {
			result.push(prefix_products[i - 1])
		} else {
			result.push(prefix_products[i - 1] + suffix_products[i + 1])
		}
	}

	process.stdout.write(result.join(','))
}

products([1, 2, 3, 4, 5])

