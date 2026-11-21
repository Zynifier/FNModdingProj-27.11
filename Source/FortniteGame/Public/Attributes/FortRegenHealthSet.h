// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TickableAttributeSetInterface.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/FortHealthSet.h"
#include "FortRegenHealthSet.generated.h"

UCLASS(BlueprintType)
class UFortRegenHealthSet : public UFortHealthSet, public ITickableAttributeSetInterface
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTick() const override;

private:
	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData HealthRegenRate;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData HealthRegenDelay;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData HealthRegenThreshold;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ShieldRegenRate;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ShieldRegenDelay;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Health", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ShieldRegenThreshold;

};

