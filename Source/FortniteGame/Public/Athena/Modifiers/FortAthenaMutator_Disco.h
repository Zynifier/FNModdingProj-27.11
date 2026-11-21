// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortTypes.h"
#include "FortAthenaMutator_Disco.generated.h"

class AAthenaCapturePoint;
class AFortPlayerStateAthena;
class AFortTeamInfoAthena;

UENUM()
enum class EControlPointState : uint8
{
	None = 0,
	Disabled = 1,
	Enabled = 2,
};

USTRUCT(BlueprintType)
struct FControlPointAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointAssetData")
	TSubclassOf<AAthenaCapturePoint> CapturePointClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointAssetData")
	FScalableFloat SpawnDistanceFromGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ControlPointAssetData")
	FVector2D MinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ControlPointAssetData")
	FVector2D CompassIconScale;

};

USTRUCT()
struct FControlPointInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AAthenaCapturePoint> ControlPoint;

	UPROPERTY()
	EControlPointState ControlPointState;

	UPROPERTY()
	int32 SpawnDataIdx;

	UPROPERTY()
	float SpawnTime;

	UPROPERTY()
	float EnableTime;

	UPROPERTY()
	float DisableTime;

	UPROPERTY()
	uint8 PrevOwningTeam;

	UPROPERTY()
	TObjectPtr<AFortTeamInfoAthena> CachedOwningTeamInfo;

	UPROPERTY()
	float PointAccrualTime;

	UPROPERTY()
	float PointsRemainder;

	UPROPERTY()
	float BonusPointAccrualTime;

	UPROPERTY()
	float BonusPointsRemainder;

	UPROPERTY()
	float CachedPointAccrualValue;

	UPROPERTY()
	float CachedBonusPointAccrualValue;

	UPROPERTY()
	bool bPointFinished;

	UPROPERTY()
	int32 CachedSafeZonePhaseWhenToSpawn;

	UPROPERTY()
	bool bIgnoreForOrderMessaging;

	UPROPERTY()
	bool bAlwaysInPlay;

	UPROPERTY()
	float TimeOfShutdown;

};

USTRUCT(BlueprintType)
struct FControlPointSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat SpawnDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat SafeZonePhaseWhenToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat SafeZonePhaseWhereToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat EnableDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat EnableInSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat DisableDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat DisableInSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat PointsEarnedPerSecond;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat BonusPointsEarnedPerSecond;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	FScalableFloat bIgnoreForOrderMessaging;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	int32 IconMaterialIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ControlPointSpawnData")
	bool bAlwaysInPlay;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Disco : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnCaptureLock(AAthenaCapturePoint* CapturePoint, uint8 LockTeam, bool bIsNewLock);

	UFUNCTION()
	void OnCaptureLockBroken(AAthenaCapturePoint* CapturePoint, uint8 LockTeam, uint8 BreakTeam);

protected:
	UFUNCTION()
	bool IsRespawningAllowed();

	UFUNCTION()
	void OnGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event);

	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	FScalableFloat GoalScoreToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	FScalableFloat PointAccrualFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	FScalableFloat LastRespawnableSafeZone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	FScalableFloat LastSafeZone;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Disco")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(Replicated)
	int32 LastRespawnableSafeZoneIndex;

	UPROPERTY(Transient)
	bool bRespawnWarningGiven;

	UPROPERTY(Transient)
	int32 LastSafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	FControlPointAssetData ControlPointAssets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Disco")
	TArray<FControlPointSpawnData> ControlPointSpawnData;

	UPROPERTY(Transient)
	TArray<FControlPointInstanceData> SpawnedControlPoints;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> DancingPlayerList;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> PrevDancingPlayerList;

	UPROPERTY(Transient)
	float TimeUntilPointAccrual;

	UPROPERTY(Transient)
	int32 SentDiscoOpenedMessagesIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_FirstCapturePointsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_SecondCapturePointsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_ThirdCapturePointsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_LastCapturePointsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_CapturePointsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_CapturePointsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_EnemyCapturedAllPoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_AlliesCapturedAllPoints;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_AllyCapturePointLost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_EnemyAboutToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_AlliesAboutToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_NoMoreRespawnsWarning;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoMessages")
	FAthenaGameMessageData GameMsg_NoMoreRespawns;

};

