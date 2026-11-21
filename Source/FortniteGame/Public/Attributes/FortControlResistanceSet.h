// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TickableAttributeSetInterface.h"
#include "Attributes/FortAttributeSet.h"
#include "FortControlResistanceSet.generated.h"

UCLASS(BlueprintType)
class UFortControlResistanceSet : public UFortAttributeSet, public ITickableAttributeSetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ControlResistance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxControlResistance(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Category="Control Resistance")
	FFortGameplayAttributeData ImpactDamage;

	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTick() const override;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ControlResistance, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ControlResistance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxControlResistance, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxControlResistance;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ControlResistanceRegenRate;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ControlResistanceRegenDelay;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ControlResistanceRegenThreshold;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData KnockbackThreshold;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Control Resistance", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData KnockbackMultiplier;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ImpactDamageResistance;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ImpactDamageMultiplier;

};

