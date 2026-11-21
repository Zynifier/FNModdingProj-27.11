// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemAttribute.generated.h"

UENUM(BlueprintType)
enum class EAttributeCombineLogic_Math : uint8
{
	MustMatch = 0,
	UseTarget = 1,
	Combine = 2,
	Average = 3,
	Highest = 4,
	Lowest = 5,
};

/**
 * Object class representing an attribute for an item/component. Never instantiated outside of CDO.
 * All attribute subclasses that represent a new type should implement the typedef ValueType and implement DECLARE_ITEM_ATTRIBUTE_DATA_ACCESSORS macro after it.
 * Attributes representing new types can also use DECLARE_ITEM_ATTRIBUTE_ACCESSORS() after the class declaration to implement easy to use global static templated accessor functions.
 */
UCLASS(Abstract)
class ITEMIZATIONCORERUNTIME_API UItemAttribute : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Attribute")
	FText GetAttributeDescription() const;

	UFUNCTION(BlueprintPure, Category="Attribute")
	FText GetAttributeName() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	FText AttributeName;

	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	FText AttributeDescription;

	UPROPERTY(Transient)
	TArray<uint8> DefaultValueAsData;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_Bool : public UItemAttribute
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	bool DefaultValue;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_Decimal : public UItemAttribute
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	double DefaultValue;

	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	EAttributeCombineLogic_Math CombineLogic;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_Int : public UItemAttribute
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	int64 DefaultValue;

	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	EAttributeCombineLogic_Math CombineLogic;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_String : public UItemAttribute
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	FString DefaultValue;

};

