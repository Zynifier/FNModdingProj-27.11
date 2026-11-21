// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TypedParameter.generated.h"

/**
 * constrain the types allowed for TypedVariant
 * simplify the blueprint customization and ui/ux
 */
UENUM()
enum class EParameterType : uint8
{
	Bool = 0 UMETA(DisplayName="bool"),
	Double = 1 UMETA(DisplayName="double"),
	Float = 2 UMETA(DisplayName="float"),
	Int8 = 3 UMETA(DisplayName="int8"),
	Int16 = 4 UMETA(DisplayName="int16"),
	Int32 = 5 UMETA(DisplayName="int32"),
	Int64 = 6 UMETA(DisplayName="int64"),
	Name = 7 UMETA(DisplayName="FName"),
	String = 8 UMETA(DisplayName="FString"),
	UInt8 = 9 UMETA(DisplayName="uint8"),
	UInt16 = 10 UMETA(DisplayName="uint16"),
	UInt32 = 11 UMETA(DisplayName="uint32"),
	UInt64 = 12 UMETA(DisplayName="uint64"),
	Num = 13 UMETA(Hidden),
	Invalid = 14 UMETA(Hidden),
};

/**
 * Wrapper for FVariant, an extensible union of multiple types
 *
 * exposed to blueprints as a "Type Parameter", which in blueprints:
 * - allows the user to select the type the parameter represents
 * - assign the value for the type
 * 
 * We can then retrieve the underlying value by checking what type is stored
 * and reading the value accordingly
 * 
 * Serializes as an FVariant, which serializes the value as a byte array.
 */
USTRUCT()
struct HARMONIXDSP_API FTypedParameter
{
	GENERATED_BODY()

};

