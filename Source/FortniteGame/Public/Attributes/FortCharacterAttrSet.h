// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortCharacterAttrSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortCharacterAttrSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_Fortitude(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxCharacterLevel(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Offense(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Resistance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Tech(const FFortGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Fortitude, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Fortitude;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Offense, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Offense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Tech, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Tech;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Resistance, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Resistance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxCharacterLevel, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxCharacterLevel;

};

