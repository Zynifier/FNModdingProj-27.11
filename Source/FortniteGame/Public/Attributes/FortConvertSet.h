// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortConvertSet.generated.h"

UCLASS(BlueprintType)
class UFortConvertSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ConvertResistance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxConvertResistance(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Category="Convert")
	FFortGameplayAttributeData ConvertDamage;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ConvertResistance, Category="Convert", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ConvertResistance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxConvertResistance, Category="Convert", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxConvertResistance;

};

