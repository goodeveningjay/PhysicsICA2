// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyMath.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyVector3Component.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSICA2_API UMyVector3Component : public UActorComponent
{
	GENERATED_BODY()


public:	

	real x;
	real y;
	real z;

private:
	real pad; // data padding for alignment

public:

	// Sets default values for this component's properties
	UMyVector3Component() : x(0), y(0), z(0) {}

	// explicit constructor creates vector with given components
	UMyVector3Component(const real x, const real y, const real z) : x(x), y(y), z(z) {}
	
	// Flips all components of the vector
	void invertMyVector()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	real real_sqrt(real n) const
	{
		// Square root function utilising defined "real" datatype.
		// Returns real number.
		real rSqrt = sqrt(n);
		return rSqrt;
	}

	// Gets the magnitude of this vector.
	real magnitude() const
	{
		return real_sqrt((x * x) + (y * y) + (z * z));

	}

	// Gets the squared magnitude of this vector for quick comparison cases
	real squareMagnitude() const
	{
		return ((x * x) + (y * y) + (z * z));
	}

	//Turns a non-zero vector into a vector of unit length.
	void normalise()
	{
		real l = magnitude();
		if (l > 0)
		{
			(*this) *= ((real)1) / l;
		}
	}

	// Multiply vector by given scalar
	void operator*=(const real value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	// Returns a copy of this vector scaled the given value
	UMyVector3Component operator*(const real value) const
	{
		return UMyVector3Component(x * value, y * value, z * value);
	}

	// Vector Addition
	void operator+=(const UMyVector3Component& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	// Return the value of given vector addition
	UMyVector3Component operator+(const UMyVector3Component& v) const
	{
		return UMyVector3Component(x + v.x, y + v.y, z + v.z);
	}

	// Vector Subtraction
	void operator-=(const UMyVector3Component& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	// Return the value of given vector subtraction
	UMyVector3Component operator-(const UMyVector3Component& v) const
	{
		return UMyVector3Component(x - v.x, y - v.y, z - v.z);
	}

	// Vector addition while scaling by given amount
	void addScaledVector(const UMyVector3Component& vector, real scale)
	{
		x += vector.x * scale;
		y += vector.y * scale;
		z += vector.z * scale;
	}

	// Component Product vector calculation
	UMyVector3Component componentProduct(const UMyVector3Component& vector) const
	{
		return UMyVector3Component(x * vector.x, y * vector.y, z * vector.z);
	}

	void componentProductUpdate(const UMyVector3Component& vector)
	{
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;
	}

	// Dot Product vector calculation
	real dotProduct(const UMyVector3Component& vector) const
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}

	// using multiplication operator to represent dot product
	real operator *(const UMyVector3Component& vector) const
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}

	// Vector Product calculation
	UMyVector3Component vectorProduct(const UMyVector3Component& vector) const
	{
		return UMyVector3Component(y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x);
	}

	// Update this vector to be the vector product of it's current value and a given vector
	void operator %=(const UMyVector3Component& vector)
	{
		*this = vectorProduct(vector);
	}

	// Calculate and return vector product of this vector with given vector
	// Overloading % operator for convenience as there is little need for modulo division here
	UMyVector3Component operator%(const UMyVector3Component& vector) const
	{
		return UMyVector3Component(y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x);
	}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};