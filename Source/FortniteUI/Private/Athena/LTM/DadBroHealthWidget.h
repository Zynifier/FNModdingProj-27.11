// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "DadBroHealthWidget.generated.h"

class AFortAIPawn;
class AFortAthenaMutator_DadBro;
enum class EDadBroHealthType : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UDadBroHealthWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewHealthPercent(float NewHealth);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionToNewHealthState(EDadBroHealthType NewHealthType);

protected:
	UFUNCTION()
	void HandleDadBroSpawned(AFortAIPawn* DadBroPawn);

	UFUNCTION()
	void HandleMashPhaseChanged(int32 NewPhase);

	UFUNCTION()
	void UpdateFinalBossBattle();

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_DadBro> DadBroMutator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DadBroHealthWidget")
	float BossHealthRatio;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DadBroHealthWidget")
	TObjectPtr<AFortAIPawn> BossAIPawn;

};

