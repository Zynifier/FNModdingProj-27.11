// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FortAttributeSet.generated.h"

USTRUCT(BlueprintType)
struct FFortGameplayAttributeData : public FGameplayAttributeData
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	float Minimum;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	float Maximum;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	bool bIsCurrentClamped;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	bool bIsBaseClamped;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	bool bShouldClampBase;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	float UnclampedBaseValue;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	float UnclampedCurrentValue;

	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	bool bShouldScaleWithMax;

};

UCLASS(MinimalAPI)
class UFortAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

};

