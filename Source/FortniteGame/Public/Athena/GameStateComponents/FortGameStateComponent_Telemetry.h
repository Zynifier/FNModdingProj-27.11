// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortGameStateComponent_Telemetry.generated.h"

UENUM(BlueprintType)
enum class EAnalyticMatchCounts : uint8
{
	IDScannerDoorFailed = 0,
	IDSCannerDoorSuccessBelongsToFaction = 1,
	IDSCannerDoorSuccessPlayerDisguised = 2,
	IDSCannerDoorSuccessCarriedHenchman = 3,
	IDSCannerDoorSuccessCarriedHuman = 4,
	IDScannerChestFailed = 5,
	IDSCannerChestSuccessBelongsToFaction = 6,
	IDSCannerChestSuccessPlayerDisguised = 7,
	IDSCannerChestSuccessCarriedHenchman = 8,
	IDSCannerChestSuccessCarriedHuman = 9,
	HenchmenEnteredSuspiciousState = 10,
	HenchmenEnteredLostTargetState = 11,
	HenchmenEnteredThreatenedState = 12,
	HenchmenDowned = 13,
	HenchmenEliminated = 14,
	HenchmenInterrogated = 15,
	BossesEliminated = 16,
	DisguisePhoneBoothTimesEntered = 17,
	DisguiseItemTimesUsed = 18,
	HiddenPassagesTimesEntered = 19,
	CameraOrSentryTimesEnteredCautionState = 20,
	CameraOrSentryTimesEnteredAltertedState = 21,
	CameraOrSentryTimesDestroyed = 22,
	GeneratorTimesDisabled = 23,
	UmbrellaNumberOfDashes = 24,
	UmbrellaNumberUsedToFloat = 25,
	UmbrellaAmountDamageBlocked = 26,
	UmbrellaBulletsBlocked = 27,
	UmbrellaMeleeHitsBlocked = 28,
	Count = 29,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_Telemetry : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_Telemetry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Transient)
	TArray<int32> MatchCounts;

};

