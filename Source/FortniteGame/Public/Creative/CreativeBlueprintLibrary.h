// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Creative/FortCreativeEventSystemType.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "FortSubGameTypes.h"
#include "OnlineLinkId.h"
#include "CreativeBlueprintLibrary.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortMinigame;
class AFortPlayerControllerAthena;
class AFortPlayerState;
class APawn;
class IFortUserOptionSettings;
class UActorComponent;
class UCurveFloat;
class UFortCreativeGeneralThrottleManager;
class UFortGameStateComponent_UpdateSavedPositions;
class UFortItemDefinition;
class UFortLevelSaveComponent;
class UFortMinigameManager;
class UFortMissionEventParams;
class UObject;
class UWorld;
enum class ECreativeQuestStat : uint8;
enum class EDynamicXpCalibrationPhase : uint8;
enum class EFortCreativeEventSystemType : uint8;
enum class EFortVolumeType : uint8;
enum class ESubGame : uint8;

USTRUCT(BlueprintType)
struct FFortCreativeAnimateFloatCurveResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeAnimateFloatCurveResult")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeAnimateFloatCurveResult")
	bool bComplete;

};

UCLASS(BlueprintType, Blueprintable)
class UCreativeBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Validation")
	static bool ActorVolumeHasBetaKnobPermission(const AActor* ActorToCheck, const FString& OptionKey);

	UFUNCTION(BlueprintCallable)
	static FFortCreativeAnimateFloatCurveResult AnimateFloatCurve(const float DeltaTime, UPARAM(ref) float& CurrentTime, UCurveFloat* FCurve, const float TotalAnimationTime, const bool bInvertTime);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void BroadcastMissionEvent(const UObject* WorldContextObject, const ECreativeQuestStat Stat, UFortMissionEventParams* Params);

	UFUNCTION(BlueprintCallable)
	static void DestroyActorByType(AActor* InActor);

	UFUNCTION(BlueprintCallable)
	static TArray<AActor*> GetActorsRelevantToActorOfType(const AActor* PrimaryActor, TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable, Category="CabinMode")
	static FText GetCabinModeLabelOverride(const FText& BaseLabel, int32 Number);

	UFUNCTION(BlueprintPure)
	static TArray<FString> GetCreativeBetaPermissionTags(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static UFortCreativeGeneralThrottleManager* GetCreativeGeneralThrottleManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure)
	static FString GetCreativeIslandCode(const AFortPlayerControllerAthena* PlayerControllerAthena);

	UFUNCTION(BlueprintPure)
	static int32 GetCreativeIslandMatchmakingMaxPlayers(const AFortPlayerControllerAthena* PlayerControllerAthena);

	UFUNCTION(BlueprintPure)
	static bool GetCuratedHubMnemonic(UWorld* World, FString& OutMnemonic);

	UFUNCTION(BlueprintPure)
	static bool GetCuratedIslandMnemonicForLinkCode(UWorld* World, int32 LinkCodeNumber, bool bLoadRandomLinkCode, FString& OutMnemonic);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static bool GetCuratedIslandMnemonicFromMatchAssignment(const UObject* WorldContextObject, FOnlineLinkId& OutLinkId);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static EFortVolumeType GetExperienceType(const AActor* ExperienceContextActor);

	UFUNCTION(BlueprintPure, Category="FortLevelSave")
	static UFortLevelSaveComponent* GetFortLevelSaveComponentForActor(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable, Category="Creative Devices")
	static UFortMinigameManager* GetMinigameManager(AController* Controller, ESubGame SubGame = ESubGame::Invalid);

	UFUNCTION(BlueprintPure, Category="Creative Devices")
	static FName GetNameFromCollisionProfile(FCollisionProfileName InCollisionProfile);

	UFUNCTION(BlueprintPure)
	static int32 GetNumCuratedIslandCodes(UWorld* World);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static UFortGameStateComponent_UpdateSavedPositions* GetOrCreateSavePositionsComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static const AFortPlayerState* GetPlayerStateFromUniqueNetID(const UObject* WorldContextObject, const FUniqueNetIdRepl& NetIDToGet);

	UFUNCTION(BlueprintPure)
	static EDynamicXpCalibrationPhase GetXpCalibrationPhase(const FCreativeLoadedLinkData& LinkData);

	UFUNCTION()
	static void HandleActorEnteredContainer(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AActor* Container);

	UFUNCTION()
	static void HandleActorExitedContainer(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AActor* Container);

	UFUNCTION(BlueprintPure, Category="UI")
	static bool HasClassesVisibleToUI(const AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	static bool IsActorInModeratedIsland(AActor* RelevantActor);

	UFUNCTION(BlueprintPure, Category="Creative Devices")
	static bool IsActorInSavableSpace(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Validation")
	static bool IsActorLocked(const AActor* ActorToCheck);

	UFUNCTION(BlueprintCallable)
	static bool IsActorRelevantToActor(const AActor* PrimaryActor, const AActor* ActorToCheckIfRelevant);

	UFUNCTION(BlueprintPure)
	static bool IsAPreviewActor(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Validation")
	static bool IsBlockListedItemDefinition(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeDevice(const ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintPure)
	static bool IsDirectBindingEnabled(const TScriptInterface<IFortUserOptionSettings> UserOptionSettings, const EFortCreativeEventSystemType FallbackType = EFortCreativeEventSystemType::DirectBinding);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static bool IsInCabinMode(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure)
	static bool IsIslandCurated(const UWorld* World, const FString& IslandMnemonic);

	UFUNCTION(BlueprintCallable)
	static bool IsLocationRelevantToActor(const AActor* PrimaryActor, FVector Location);

	UFUNCTION(BlueprintCallable)
	static bool IsObjectInModeratedIsland(UObject* Object);

	UFUNCTION(BlueprintPure)
	static bool IsUseRestrictionComponentDebuggingEnabled();

	UFUNCTION(BlueprintPure)
	static bool IsValkyrieLink(const FCreativeLoadedLinkData& InLinkData);

	UFUNCTION(BlueprintPure, Category="Validation")
	static bool IsWhiteListedItemDefinition(const UFortItemDefinition* ItemDefinition, const AActor* ActorContext = nullptr);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Log Creative Streaming Message"))
	static void LogCreativeStreamingMessage(const FString& Message);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Log HUD Message Warning"))
	static void LogHUDMessageWarning(const FString& InString = TEXT("Generic HUD Message"));

	UFUNCTION(BlueprintCallable)
	static bool MakeOnlineLinkCode(const FString& LinkCode, bool bRemoveVersion, FOnlineLinkId& OutLinkId, int32& OutVersion);

	UFUNCTION(BlueprintCallable)
	static void ResavePIDs(const TArray<FString>& PIDPaths);

	UFUNCTION(BlueprintPure, Category="Maths")
	static TArray<FVector> SegmentCylinderIntersection(const FVector& SegmentStart, const FVector& SegmentEnd, const FVector& CylinderOrigin, const float CylinderRadius);

	UFUNCTION(BlueprintPure, Category="Maths")
	static TArray<FVector> SegmentSphereIntersection(const FVector& SegmentStart, const FVector& SegmentEnd, const FVector& SphereOrigin, const float SphereRadius);

	UFUNCTION(BlueprintCallable, meta=(AdvancedDisplay="InitialStartDelay, InitialStartDelayVariance"))
	static FTimerHandle SetLoopingTimer_MaxOncePerFrame(FTimerDynamicDelegate Delegate, float Time, float InitialStartDelay = 0.000000f, float InitialStartDelayVariance = 0.000000f);

	UFUNCTION(BlueprintCallable)
	static void SetUserOptionOverrideValue(const TArray<FString>& MapPaths, const FString& OptionKey, const FString& NewValue);

	UFUNCTION(BlueprintCallable, Category="CabinMode")
	static bool ShouldUseCabinModeLabel(const FText& BaseLabel, const FString& Label);

	UFUNCTION(BlueprintCallable, Category="Heatmap Thermometer", meta=(WorldContext="WorldContextObject"))
	static void UpdateInGameMapHeatmapTexture(const UObject* WorldContextObject);

};

