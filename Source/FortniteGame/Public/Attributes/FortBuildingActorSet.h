// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/FortHealthSet.h"
#include "FortBuildingActorSet.generated.h"

UCLASS()
class UFortBuildingActorSet : public UFortHealthSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BuildTime(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_RepairTime(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildTime, Category="Building", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData BuildTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RepairTime, Category="Building", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData RepairTime;

};

