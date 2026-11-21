// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/CreativeBlueprintLibrary.h"

bool UCreativeBlueprintLibrary::ActorVolumeHasBetaKnobPermission(const AActor* ActorToCheck, const FString& OptionKey)
{
	return false;
}

FFortCreativeAnimateFloatCurveResult UCreativeBlueprintLibrary::AnimateFloatCurve(const float DeltaTime, float& CurrentTime, UCurveFloat* FCurve, const float TotalAnimationTime, const bool bInvertTime)
{
	return FFortCreativeAnimateFloatCurveResult();
}

void UCreativeBlueprintLibrary::BroadcastMissionEvent(const UObject* WorldContextObject, const ECreativeQuestStat Stat, UFortMissionEventParams* Params)
{
}

void UCreativeBlueprintLibrary::DestroyActorByType(AActor* InActor)
{
}

TArray<AActor*> UCreativeBlueprintLibrary::GetActorsRelevantToActorOfType(const AActor* PrimaryActor, TSubclassOf<AActor> ActorClass)
{
	return TArray<AActor*>();
}

FText UCreativeBlueprintLibrary::GetCabinModeLabelOverride(const FText& BaseLabel, int32 Number)
{
	return FText();
}

TArray<FString> UCreativeBlueprintLibrary::GetCreativeBetaPermissionTags(const UFortItemDefinition* ItemDefinition)
{
	return TArray<FString>();
}

UFortCreativeGeneralThrottleManager* UCreativeBlueprintLibrary::GetCreativeGeneralThrottleManager(const UObject* WorldContextObject)
{
	return nullptr;
}

FString UCreativeBlueprintLibrary::GetCreativeIslandCode(const AFortPlayerControllerAthena* PlayerControllerAthena)
{
	return FString();
}

int32 UCreativeBlueprintLibrary::GetCreativeIslandMatchmakingMaxPlayers(const AFortPlayerControllerAthena* PlayerControllerAthena)
{
	return int32();
}

bool UCreativeBlueprintLibrary::GetCuratedHubMnemonic(UWorld* World, FString& OutMnemonic)
{
	return false;
}

bool UCreativeBlueprintLibrary::GetCuratedIslandMnemonicForLinkCode(UWorld* World, int32 LinkCodeNumber, bool bLoadRandomLinkCode, FString& OutMnemonic)
{
	return false;
}

bool UCreativeBlueprintLibrary::GetCuratedIslandMnemonicFromMatchAssignment(const UObject* WorldContextObject, FOnlineLinkId& OutLinkId)
{
	return false;
}

EFortVolumeType UCreativeBlueprintLibrary::GetExperienceType(const AActor* ExperienceContextActor)
{
	return EFortVolumeType();
}

UFortLevelSaveComponent* UCreativeBlueprintLibrary::GetFortLevelSaveComponentForActor(const AActor* ContextActor)
{
	return nullptr;
}

UFortMinigameManager* UCreativeBlueprintLibrary::GetMinigameManager(AController* Controller, ESubGame SubGame)
{
	return nullptr;
}

FName UCreativeBlueprintLibrary::GetNameFromCollisionProfile(FCollisionProfileName InCollisionProfile)
{
	return FName();
}

int32 UCreativeBlueprintLibrary::GetNumCuratedIslandCodes(UWorld* World)
{
	return int32();
}

UFortGameStateComponent_UpdateSavedPositions* UCreativeBlueprintLibrary::GetOrCreateSavePositionsComponent(const UObject* WorldContextObject)
{
	return nullptr;
}

const AFortPlayerState* UCreativeBlueprintLibrary::GetPlayerStateFromUniqueNetID(const UObject* WorldContextObject, const FUniqueNetIdRepl& NetIDToGet)
{
	return nullptr;
}

EDynamicXpCalibrationPhase UCreativeBlueprintLibrary::GetXpCalibrationPhase(const FCreativeLoadedLinkData& LinkData)
{
	return EDynamicXpCalibrationPhase();
}

void UCreativeBlueprintLibrary::HandleActorEnteredContainer(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AActor* Container)
{
}

void UCreativeBlueprintLibrary::HandleActorExitedContainer(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AActor* Container)
{
}

bool UCreativeBlueprintLibrary::HasClassesVisibleToUI(const AFortMinigame* Minigame)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsActorInModeratedIsland(AActor* RelevantActor)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsActorInSavableSpace(const AActor* Actor)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsActorLocked(const AActor* ActorToCheck)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsActorRelevantToActor(const AActor* PrimaryActor, const AActor* ActorToCheckIfRelevant)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsAPreviewActor(AActor* Actor)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsBlockListedItemDefinition(const UFortItemDefinition* ItemDefinition)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsCreativeDevice(const ABuildingActor* BuildingActor)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsDirectBindingEnabled(const TScriptInterface<IFortUserOptionSettings> UserOptionSettings, const EFortCreativeEventSystemType FallbackType)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsInCabinMode(const UObject* WorldContextObject)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsIslandCurated(const UWorld* World, const FString& IslandMnemonic)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsLocationRelevantToActor(const AActor* PrimaryActor, FVector Location)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsObjectInModeratedIsland(UObject* Object)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsUseRestrictionComponentDebuggingEnabled()
{
	return false;
}

bool UCreativeBlueprintLibrary::IsValkyrieLink(const FCreativeLoadedLinkData& InLinkData)
{
	return false;
}

bool UCreativeBlueprintLibrary::IsWhiteListedItemDefinition(const UFortItemDefinition* ItemDefinition, const AActor* ActorContext)
{
	return false;
}

void UCreativeBlueprintLibrary::LogCreativeStreamingMessage(const FString& Message)
{
}

void UCreativeBlueprintLibrary::LogHUDMessageWarning(const FString& InString)
{
}

bool UCreativeBlueprintLibrary::MakeOnlineLinkCode(const FString& LinkCode, bool bRemoveVersion, FOnlineLinkId& OutLinkId, int32& OutVersion)
{
	return false;
}

void UCreativeBlueprintLibrary::ResavePIDs(const TArray<FString>& PIDPaths)
{
}

TArray<FVector> UCreativeBlueprintLibrary::SegmentCylinderIntersection(const FVector& SegmentStart, const FVector& SegmentEnd, const FVector& CylinderOrigin, const float CylinderRadius)
{
	return TArray<FVector>();
}

TArray<FVector> UCreativeBlueprintLibrary::SegmentSphereIntersection(const FVector& SegmentStart, const FVector& SegmentEnd, const FVector& SphereOrigin, const float SphereRadius)
{
	return TArray<FVector>();
}

FTimerHandle UCreativeBlueprintLibrary::SetLoopingTimer_MaxOncePerFrame(FTimerDynamicDelegate Delegate, float Time, float InitialStartDelay, float InitialStartDelayVariance)
{
	return FTimerHandle();
}

void UCreativeBlueprintLibrary::SetUserOptionOverrideValue(const TArray<FString>& MapPaths, const FString& OptionKey, const FString& NewValue)
{
}

bool UCreativeBlueprintLibrary::ShouldUseCabinModeLabel(const FText& BaseLabel, const FString& Label)
{
	return false;
}

void UCreativeBlueprintLibrary::UpdateInGameMapHeatmapTexture(const UObject* WorldContextObject)
{
}
