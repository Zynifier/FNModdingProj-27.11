// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_Mash.h"
#include "MashBossBattleWidget.generated.h"

class AFortAthenaMutator_Mash;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UMashBossBattleWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBossFightStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBossHealthUpdate();

protected:
	UFUNCTION()
	void UpdateBossBattle(const FMashBossHealthShieldData& BossHealthShieldData);

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashBossBattleWidget")
	TObjectPtr<AFortAthenaMutator_Mash> MashMutatorRef;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashBossBattleWidget")
	float CurrentBossHealth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashBossBattleWidget")
	float TotalBossHealth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashBossBattleWidget")
	float BossHealthRatio;

};

