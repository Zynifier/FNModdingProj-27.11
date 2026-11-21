// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortActorIndicatorWidget.h"
#include "AthenaSpectatorNameplateBase.generated.h"

class AActor;
class AFortPlayerPawn;
class UAthenaRemotePlayerViewData;
enum class EAthenaSpectatorNameplateDetailState : uint8;
enum class EAthenaSpectatorNameplateDistanceState : uint8;

UENUM(BlueprintType)
enum class EAthenaSpectatorNameplateDetailState : uint8
{
	High = 0,
	Low = 1,
	Arrow = 2,
	Off = 3,
};

UENUM(BlueprintType)
enum class EAthenaSpectatorNameplateDistanceState : uint8
{
	Near = 0,
	MidDistance = 1,
	FurtherThanMaxDistance = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorNameplateBase : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetArrowTeamColorVisible(bool bArrowTeamColorVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSquadIdVisibility(bool bSquadIdVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTeamColorVisible(bool bTeamColorVisible);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDisplaySessionRankChanged(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDetailStateChanged(EAthenaSpectatorNameplateDetailState NewDetailState);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDistanceStateChanged(EAthenaSpectatorNameplateDistanceState NewDistanceState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerDataSet(UAthenaRemotePlayerViewData* InPlayerData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerNameChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& InPlayerName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSessionRankChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InGamerank);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadIdChanged(UAthenaRemotePlayerViewData* InPlayerData, uint8 InSquadId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSquadIDsDisplayModeHoldUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamColorChanged(UAthenaRemotePlayerViewData* InPlayerData, FLinearColor InTeamColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVehicleStateChanged(AActor* NewVehicle, AActor* OldVehicle);

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorNameplateBase")
	float DistanceToCameraOffsetScale;

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorNameplateBase")
	float MinZOffset;

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorNameplateBase")
	float MaxZOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaSpectatorNameplateBase")
	bool bOverrideNameplateScaleToMax;

private:
	UFUNCTION()
	void OnPlayerPawnChanged(UAthenaRemotePlayerViewData* InPlayerData, AFortPlayerPawn* InPlayerPawn);

	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaRemotePlayerViewData> PlayerData;

	UPROPERTY(Transient)
	EAthenaSpectatorNameplateDistanceState CurrentDistanceState;

	UPROPERTY(Transient)
	EAthenaSpectatorNameplateDetailState CurrentDetailState;

};

