// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "GameplayDataTracker/FortGameplayDataTrackerComponent.h"
#include "FortMangDataTrackerComponent.generated.h"

class ABuildingGameplayActor;
class AFortAthenaAIBotController;
class AFortPawn;
class AFortPlayerController;
enum class EAlertLevel : uint8;

USTRUCT()
struct FFortMangBotInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TObjectPtr<AFortAthenaAIBotController> BotController;

	UPROPERTY()
	TObjectPtr<AFortPawn> BotPawn;

	UPROPERTY()
	EAlertLevel CurrentBotAlertLevel;

};

USTRUCT()
struct FFortMangBotInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortMangBotInfo> Items;

};

USTRUCT(BlueprintType)
struct FFortMangSentryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortMangSentryInfo")
	TObjectPtr<ABuildingGameplayActor> Sentry;

	UPROPERTY(BlueprintReadWrite, Category="FortMangSentryInfo")
	EAlertLevel CurrentSentryAlertLevel;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortMangDataTrackerComponent : public UFortGameplayDataTrackerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel);

	UFUNCTION()
	void OnBotDBNOStatusChanged(AFortAthenaAIBotController* BotController, bool bIsDBNO);

	UFUNCTION()
	void OnBotDied(AFortAthenaAIBotController* BotController, AFortPawn* FortPawn);

	UFUNCTION()
	void OnBotPawnDBNOStatusChanged(AFortPawn* FortPawn, bool bIsDBNO);

	UFUNCTION(BlueprintCallable)
	void RegisterCameraInfos(const TArray<FFortMangSentryInfo>& Cameras);

	UFUNCTION(BlueprintCallable)
	void RegisterLocalPlayerController(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintCallable)
	void RegisterMangControllers(TArray<AFortAthenaAIBotController*> MangControllers);

	UFUNCTION(BlueprintCallable)
	void RegisterTurretInfos(const TArray<FFortMangSentryInfo>& Turrets);

	UFUNCTION(BlueprintCallable)
	void UnRegisterLocalPlayerController();

	UFUNCTION(BlueprintCallable)
	void UpdateCameraAlertState(ABuildingGameplayActor* CameraToUpdate, EAlertLevel NewAlertLevel);

	UFUNCTION(BlueprintCallable)
	void UpdateTurretAlertState(ABuildingGameplayActor* TurretToUpdate, EAlertLevel NewAlertLevel);

private:
	UFUNCTION(BlueprintPure)
	bool IsTrackingPerPlayer() const;

	UFUNCTION()
	void OnRep_BotInfos();

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag NumMangBotsThreatenedEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag MangBotsTargetedThreatenedEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag NumMangBotsAlertedEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag NumMangBotsDBNOEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag NumMangBotsUnawareEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag NumMangBossesThreatenedEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FGameplayTag BossIdentifyingTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumTurretsThreatenedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumTurretsAlertedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumTurretsUnawareEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumCamerasThreatenedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumCamerasAlertedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMangDataTrackerComponent", meta=(AllowPrivateAccess="true"))
	FGameplayTag NumCamerasUnawareEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat UnawareNearDistance;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat UnawareFarDistance;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat AlertNearDistance;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat AlertFarDistance;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ThreatenedFarDistance;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat DistancePercentLerpExponent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ShouldUseDotProductForThreatEvents;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ThreatEventsDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ThreatEventsDotProductFailureMultiplier;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat TargetedThreatenedGuaranteedRange;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat TargetedThreatenedNearComparisonRange;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat BotFacingNearTargetedThreatenedDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat BotFacingFarTargetedThreatenedDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat PlayerFacingNearTargetedThreatenedDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat PlayerFacingFarTargetedThreatenedDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ShouldUseTargetedThreatenedEvent;

	UPROPERTY(EditAnywhere, Category="FortMangDataTrackerComponent")
	FScalableFloat ShouldTrackPerPlayer;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaAIBotController>> MangBotControllers;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BotInfos)
	FFortMangBotInfoArray BotInfos;

	UPROPERTY(Transient)
	TArray<FFortMangSentryInfo> CameraInfos;

	UPROPERTY(Transient)
	TArray<FFortMangSentryInfo> TurretInfos;

};

