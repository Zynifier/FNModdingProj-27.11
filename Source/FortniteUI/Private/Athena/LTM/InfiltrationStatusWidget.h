// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_Infiltration.h"
#include "InfiltrationStatusWidget.generated.h"

class UInfiltrationIntelStatusWidget;
class USoundBase;
enum class EIntelStateEnum : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationIntelStatusWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetIntelState(EIntelStateEnum NewState);

	UPROPERTY(EditInstanceOnly, Category="InfiltrationIntelStatusWidget")
	int32 SpawnerIndex;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetIsGroundTimer(bool bIsGroundTimer);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimerVisuals(float TimeRemaining, float TotalTime);

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationStatusWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentRound() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumOfRounds() const;

	UFUNCTION(BlueprintPure)
	USoundBase* GetSoundFromIntelState(EIntelStateEnum InState, bool bIsDefender) const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentlyADraw() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerAttacking() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerDefending() const;

	UPROPERTY()
	FInfiltrationModeState PrevModeState;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UInfiltrationIntelStatusWidget>> IntelStatusWidgets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InfiltrationStatusWidget")
	TMap<EIntelStateEnum, TObjectPtr<USoundBase>> AttackerAudioCues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InfiltrationStatusWidget")
	TMap<EIntelStateEnum, TObjectPtr<USoundBase>> DefenderAudioCues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InfiltrationStatusWidget")
	TMap<EIntelStateEnum, TObjectPtr<USoundBase>> SpamSounds;

	UPROPERTY(EditAnywhere, Category="InfiltrationStatusWidget")
	float SpamThrottle;

};

