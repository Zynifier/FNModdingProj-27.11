// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortCreativeMoveTool.h"
#include "Net/UnrealNetwork.h"

void AFortCreativeMoveTool::AdjustOptionsBasedOnSelectionProperty(ESelectionProperty UpdatedSelectionProperty)
{
}

bool AFortCreativeMoveTool::CanUtilizeMoveToolSpawningFunctionality_Implementation()
{
	return false;
}

void AFortCreativeMoveTool::ClientAddItemToMoveToolComplete_Implementation(AFortPlayerControllerAthena* FortPC)
{
}

void AFortCreativeMoveTool::ClientDeactiveWeaponAndState_Implementation()
{
}

void AFortCreativeMoveTool::ClientStartInteracting_Implementation(UObjectInteractionBehavior* NewActiveMovementMode, const TArray<FCreativeSelectedActorInfo>& NewSelectedActors, const FTransform& NewSelectionToWorld, const FBox& NewSelectionSpaceActorBounds)
{
}

void AFortCreativeMoveTool::ClientStopInteracting_Implementation()
{
}

void AFortCreativeMoveTool::DeactiveWeaponAndState()
{
}

bool AFortCreativeMoveTool::DoesBoxOverlapTerrain(const AActor* WorldContextObject, const FBox Box)
{
	return false;
}

void AFortCreativeMoveTool::Finished_CutDuplicateStartInteractingOnServer()
{
}

void AFortCreativeMoveTool::Finished_DuplicateStartInteractingOnServer()
{
}

UObjectInteractionBehavior* AFortCreativeMoveTool::GetActiveMovementMode() const
{
	return nullptr;
}

bool AFortCreativeMoveTool::GetAllowGravityOnPlace() const
{
	return false;
}

float AFortCreativeMoveTool::GetAverageScaleModifier() const
{
	return float();
}

bool AFortCreativeMoveTool::GetClientNeedsToProcessNewlyPlacedActors() const
{
	return false;
}

UFortObjectMoverInputComponent* AFortCreativeMoveTool::GetCreativeMoveToolInputComponent() const
{
	return nullptr;
}

EHitTraceRule AFortCreativeMoveTool::GetCurrentHitTraceRule()
{
	return EHitTraceRule();
}

AFortVolume* AFortCreativeMoveTool::GetCurrentVolume(const bool bMustHavePermissions)
{
	return nullptr;
}

uint8 AFortCreativeMoveTool::GetGridSnapIndex() const
{
	return uint8();
}

TArray<FVector> AFortCreativeMoveTool::GetGridSnapRatios() const
{
	return TArray<FVector>();
}

int32 AFortCreativeMoveTool::GetMultiselectLimit()
{
	return int32();
}

uint8 AFortCreativeMoveTool::GetRotationAxisIndex() const
{
	return uint8();
}

EScaleAxis AFortCreativeMoveTool::GetSelectedScaleAxis() const
{
	return EScaleAxis();
}

bool AFortCreativeMoveTool::GetShouldAutoTractorBeam() const
{
	return false;
}

bool AFortCreativeMoveTool::GetShouldUsePrecisionGridSnapping() const
{
	return false;
}

float AFortCreativeMoveTool::GetTargetTractorBeamOffset() const
{
	return float();
}

void AFortCreativeMoveTool::GetValidQueuedActorsAsArray(TArray<AActor*>& ValidQueuedActors)
{
}

void AFortCreativeMoveTool::HandleActivateRotationModePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleActivateScaleModePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleActivateTranslateModePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleActorSelectedForQueuePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleActorSelectedForQueueReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleActorSelectedHeldDownLongEnough_Implementation()
{
}

void AFortCreativeMoveTool::HandleClearMultiSelectQueuePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleCopyPickupPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleCopyPickupReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleDeleteHeldDownLongEnough_Implementation()
{
}

void AFortCreativeMoveTool::HandleDeletePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleDeleteReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleDropToFloorPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleDuplicateActorPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleDuplicateActorReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleExitHeldDownLongEnough_Implementation()
{
}

void AFortCreativeMoveTool::HandleExitOrDeletePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleExitPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleExitReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleHitTraceRuleHeldDownLongEnough_Implementation()
{
}

void AFortCreativeMoveTool::HandleHitTraceRulePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleHitTraceRuleReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleMirrorPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandlePickupPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandlePlaysetPreviewPlace_Implementation()
{
}

void AFortCreativeMoveTool::HandlePrecisionModePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandlePrecisionModeReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandlePullPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandlePullReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandlePushPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandlePushReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleResetRotationPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleResetScalePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateClockwisePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateClockwiseReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateCounterclockwisePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateCounterclockwiseReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSingleClockwisePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSingleClockwiseReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSingleCounterclockwisePressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSingleCounterclockwiseReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSwitchAxisPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleRotateSwitchAxisReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleDownPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleDownReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleSwitchAxisPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleSwitchAxisReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleUpPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleScaleUpReleased_Implementation()
{
}

void AFortCreativeMoveTool::HandleTransformModeDownPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleTransformModeUpPressed_Implementation()
{
}

void AFortCreativeMoveTool::HandleTurboDeleteAction()
{
}

void AFortCreativeMoveTool::IncrementOrWrapHitTraceRuleOnClient()
{
}

bool AFortCreativeMoveTool::IsMultiSelecting()
{
	return false;
}

bool AFortCreativeMoveTool::IsMultiselectingMoveOnGrid()
{
	return false;
}

bool AFortCreativeMoveTool::IsRunningOnOwningClient() const
{
	return false;
}

void AFortCreativeMoveTool::MulticastForceMoveActor_Implementation(AActor* ActorToMove, const FTransform NewTransform)
{
}

void AFortCreativeMoveTool::MulticastForceMoveActorExceptOwningClient_Implementation(AActor* ActorToMove, const FTransform NewTransform)
{
}

void AFortCreativeMoveTool::MulticastUpdateSelectionSetExceptServer_Implementation(const FTransform NewTransformToWorld)
{
}

void AFortCreativeMoveTool::MulticastUpdateSelectionSetExceptServerAndOwningClient_Implementation(const FTransform NewTransformToWorld)
{
}

void AFortCreativeMoveTool::OnClientInstigatorWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void AFortCreativeMoveTool::OnClientInstigatorWeaponUnequipped()
{
}

void AFortCreativeMoveTool::OnCreativeQuickmenuEnabledChanged(bool bEnabled)
{
}

void AFortCreativeMoveTool::OnPlaysetSelected(UFortPlaysetItemDefinition* SelectedPlayset)
{
}

void AFortCreativeMoveTool::OnRep_ActiveMovementModeReplicateToRemoteClients()
{
}

void AFortCreativeMoveTool::OnRep_AllowGravityOnPlace()
{
}

void AFortCreativeMoveTool::OnRep_BuildingsAsPropsSnapToCenter()
{
}

void AFortCreativeMoveTool::OnRep_ConnectedActorStates()
{
}

void AFortCreativeMoveTool::OnRep_CutActors()
{
}

void AFortCreativeMoveTool::OnRep_DisableCollisionActors()
{
}

void AFortCreativeMoveTool::OnRep_NewlyPlacedActors()
{
}

void AFortCreativeMoveTool::OnRep_SelectedActorsReplicateToRemoteClients()
{
}

void AFortCreativeMoveTool::OnRep_SelectionProperty()
{
}

void AFortCreativeMoveTool::OnWantedAlwaysMoveFreely(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::OnWantedCameraSpacePositioning(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::OnWantedHitTraceRule(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::OnWantedIgnoreRecentlyPlacedTime(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::OnWantsAutoTractorBeamChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortCreativeMoveTool::OnWantsGravityOnPlace(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::OnWantsPrecisionGridSnapping(UFortCreativeOption* CreativeOption, uint8 Index)
{
}

void AFortCreativeMoveTool::PopCreativeMoveToolEquippedInputComponent_Implementation()
{
}

void AFortCreativeMoveTool::PushCreativeMoveToolEquippedInputComponent_Implementation()
{
}

void AFortCreativeMoveTool::QueuedActorDestroyed(AActor* DestroyedActor)
{
}

void AFortCreativeMoveTool::ServerActorDeselected_Implementation(AActor* Actor, AFortPlayerController* InstigatorPlayer)
{
}
bool AFortCreativeMoveTool::ServerActorDeselected_Validate(AActor* Actor, AFortPlayerController* InstigatorPlayer)
{
	return true;
}

void AFortCreativeMoveTool::ServerActorSelected_Implementation(AActor* Actor, AFortPlayerController* InstigatorPlayer)
{
}
bool AFortCreativeMoveTool::ServerActorSelected_Validate(AActor* Actor, AFortPlayerController* InstigatorPlayer)
{
	return true;
}

void AFortCreativeMoveTool::ServerAddItemToMoveTool_Implementation(AFortPlayerControllerAthena* FortPC, const UFortItemDefinition* PlaysetToSpawn, bool bUseVolume)
{
}

void AFortCreativeMoveTool::ServerBatchDestroyActors_Implementation(const TArray<AActor*>& ActorsToDestroy)
{
}
bool AFortCreativeMoveTool::ServerBatchDestroyActors_Validate(const TArray<AActor*>& ActorsToDestroy)
{
	return true;
}

void AFortCreativeMoveTool::ServerClearMovementMode_Implementation(const bool bExited)
{
}
bool AFortCreativeMoveTool::ServerClearMovementMode_Validate(const bool bExited)
{
	return true;
}

void AFortCreativeMoveTool::ServerDestroyActor_Implementation(AActor* ActorToDestroy)
{
}
bool AFortCreativeMoveTool::ServerDestroyActor_Validate(AActor* ActorToDestroy)
{
	return true;
}

void AFortCreativeMoveTool::ServerDuplicateStartInteracting_Implementation(const TArray<AActor*>& Actors, const FTransform DragStart)
{
}
bool AFortCreativeMoveTool::ServerDuplicateStartInteracting_Validate(const TArray<AActor*>& Actors, const FTransform DragStart)
{
	return true;
}

void AFortCreativeMoveTool::ServerMoveSelectionSet_Implementation(const FTransform NewSelectionToWorld, const bool bShouldUpdateOwningClient)
{
}
bool AFortCreativeMoveTool::ServerMoveSelectionSet_Validate(const FTransform NewSelectionToWorld, const bool bShouldUpdateOwningClient)
{
	return true;
}

void AFortCreativeMoveTool::ServerOnNewlyPlacedActorProcessedByClient_Implementation(FOriginalAndSpawnedPair NewlyPlacedActorPair)
{
}
bool AFortCreativeMoveTool::ServerOnNewlyPlacedActorProcessedByClient_Validate(FOriginalAndSpawnedPair NewlyPlacedActorPair)
{
	return true;
}

void AFortCreativeMoveTool::ServerPlaceActorsAndClearMovementMode_Implementation(FTransform TargetTransformForBuildings)
{
}
bool AFortCreativeMoveTool::ServerPlaceActorsAndClearMovementMode_Validate(FTransform TargetTransformForBuildings)
{
	return true;
}

void AFortCreativeMoveTool::ServerResetScale_Implementation()
{
}
bool AFortCreativeMoveTool::ServerResetScale_Validate()
{
	return true;
}

void AFortCreativeMoveTool::ServerSendProgressTimerCue_Implementation(float Duration)
{
}
bool AFortCreativeMoveTool::ServerSendProgressTimerCue_Validate(float Duration)
{
	return true;
}

void AFortCreativeMoveTool::ServerSetAllowGravity_Implementation(bool bAllow)
{
}
bool AFortCreativeMoveTool::ServerSetAllowGravity_Validate(bool bAllow)
{
	return true;
}

void AFortCreativeMoveTool::ServerSetAlwaysMoveFreely_Implementation(EBuildingAsPropSetting NewSetting)
{
}
bool AFortCreativeMoveTool::ServerSetAlwaysMoveFreely_Validate(EBuildingAsPropSetting NewSetting)
{
	return true;
}

void AFortCreativeMoveTool::ServerSpawnActorWithTransform_Implementation(AActor* ActorToSpawn, FTransform TargetTransform, const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing)
{
}
bool AFortCreativeMoveTool::ServerSpawnActorWithTransform_Validate(AActor* ActorToSpawn, FTransform TargetTransform, const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing)
{
	return true;
}

void AFortCreativeMoveTool::ServerSpawnSelectedActorsWithTransform_Implementation(const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing, const bool bNotifyOwnerOnFailure)
{
}
bool AFortCreativeMoveTool::ServerSpawnSelectedActorsWithTransform_Validate(const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing, const bool bNotifyOwnerOnFailure)
{
	return true;
}

void AFortCreativeMoveTool::ServerStartInteracting_Implementation(const TArray<AActor*>& Actors, const FTransform DragStart)
{
}
bool AFortCreativeMoveTool::ServerStartInteracting_Validate(const TArray<AActor*>& Actors, const FTransform DragStart)
{
	return true;
}

void AFortCreativeMoveTool::ServerStartReselectTimer_Implementation()
{
}

void AFortCreativeMoveTool::ServerUpdateLocale_Implementation(const FString& UpdatedLocale)
{
}
bool AFortCreativeMoveTool::ServerUpdateLocale_Validate(const FString& UpdatedLocale)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateMirrored_Implementation(bool bMirrored)
{
}
bool AFortCreativeMoveTool::ServerUpdateMirrored_Validate(bool bMirrored)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdatePrecisionMode_Implementation(bool bPrecisionMode, uint8 PrecisionModeIndex)
{
}
bool AFortCreativeMoveTool::ServerUpdatePrecisionMode_Validate(bool bPrecisionMode, uint8 PrecisionModeIndex)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateRotation_Implementation(FQuat ClientRotation, bool bNewIsRotateClockwisePressed, bool bNewIsRotateCounterclockwisePressed)
{
}
bool AFortCreativeMoveTool::ServerUpdateRotation_Validate(FQuat ClientRotation, bool bNewIsRotateClockwisePressed, bool bNewIsRotateCounterclockwisePressed)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateRotationAxis_Implementation(uint8 AxisIndex)
{
}
bool AFortCreativeMoveTool::ServerUpdateRotationAxis_Validate(uint8 AxisIndex)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateScaleAxis_Implementation(EScaleAxis SelectedAxis)
{
}
bool AFortCreativeMoveTool::ServerUpdateScaleAxis_Validate(EScaleAxis SelectedAxis)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateScalePressed_Implementation(bool bNewIsScaleUpPressed, bool bNewIsScaleDownPressed)
{
}
bool AFortCreativeMoveTool::ServerUpdateScalePressed_Validate(bool bNewIsScaleUpPressed, bool bNewIsScaleDownPressed)
{
	return true;
}

void AFortCreativeMoveTool::ServerUpdateTractorBeam_Implementation(float NewTargetTractorBeamOffset, bool bNewIsPushPressed, bool bNewIsPullPressed)
{
}
bool AFortCreativeMoveTool::ServerUpdateTractorBeam_Validate(float NewTargetTractorBeamOffset, bool bNewIsPushPressed, bool bNewIsPullPressed)
{
	return true;
}

void AFortCreativeMoveTool::SetLastBoundController(APlayerController* Controller)
{
}

void AFortCreativeMoveTool::SetTargetingState(bool bNewTargetingState)
{
}

void AFortCreativeMoveTool::SetupMIDForComponent(UMeshComponent* MeshComponent)
{
}

void AFortCreativeMoveTool::SpawnPlaysetVolumeOnServer_Implementation(const UFortPlaysetItemDefinition* Playset, const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
}
bool AFortCreativeMoveTool::SpawnPlaysetVolumeOnServer_Validate(const UFortPlaysetItemDefinition* Playset, const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
	return true;
}

void AFortCreativeMoveTool::TurboBuildAttemptToPlace()
{
}

void AFortCreativeMoveTool::UnholsterWeapon()
{
}

void AFortCreativeMoveTool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativeMoveTool, SelectedActorsReplicateToRemoteClients);
	DOREPLIFETIME(AFortCreativeMoveTool, ActiveMovementModeReplicateToRemoteClients);
	DOREPLIFETIME(AFortCreativeMoveTool, bIsPreviewingMove);
	DOREPLIFETIME(AFortCreativeMoveTool, InteractionBehaviors);
	DOREPLIFETIME(AFortCreativeMoveTool, DeleteObjectsInteractionBehavior);
	DOREPLIFETIME(AFortCreativeMoveTool, PlaysetPreviewInteractionBehavior);
	DOREPLIFETIME(AFortCreativeMoveTool, ConnectedActorStates);
	DOREPLIFETIME(AFortCreativeMoveTool, ScaleModifier);
	DOREPLIFETIME(AFortCreativeMoveTool, SelectionProperty);
	DOREPLIFETIME(AFortCreativeMoveTool, NewlyPlacedActors);
	DOREPLIFETIME(AFortCreativeMoveTool, CutActors);
	DOREPLIFETIME(AFortCreativeMoveTool, DisableCollisionActors);
	DOREPLIFETIME(AFortCreativeMoveTool, bAllowGravityOnPlace);
	DOREPLIFETIME(AFortCreativeMoveTool, bClientNeedsToProcessNewlyPlacedActors);
	DOREPLIFETIME(AFortCreativeMoveTool, bAlwaysMoveFreely);
	DOREPLIFETIME(AFortCreativeMoveTool, bBuildingsAsPropsSnapToCenter);
}

void UObjectInteractionBehavior::EndCreativeInteraction_Implementation()
{
}

void UObjectInteractionBehavior::ExitCreativeInteraction_Implementation(const bool bShouldClearActiveInteractionMode)
{
}

AFortCreativeMoveTool* UObjectInteractionBehavior::GetFortCreativeMoveTool() const
{
	return nullptr;
}

AFortPlayerController* UObjectInteractionBehavior::GetFortPlayerController() const
{
	return nullptr;
}

void UObjectInteractionBehavior::GetSelectedActors(TArray<AActor*>& SelectedActors)
{
}

void UObjectInteractionBehavior::GetSelectedActorsMeshComponents(TArray<UMeshComponent*>& Components)
{
}

void UObjectInteractionBehavior::HandleDuplicateActor_Implementation()
{
}

bool UObjectInteractionBehavior::IsActorClassAllowed_Implementation(TSubclassOf<UObject> Class)
{
	return false;
}

bool UObjectInteractionBehavior::IsActorClassForbidden_Implementation(TSubclassOf<UObject> Class)
{
	return false;
}

bool UObjectInteractionBehavior::IsSelectionSetInValidPosition()
{
	return false;
}

void UObjectInteractionBehavior::PlayGameplayAbility(const TSubclassOf<UFortGameplayAbility> ActivatedAbilityClass)
{
}

void UObjectInteractionBehavior::ReceiveSpawnedActor_Implementation(AActor* SpawnedActor)
{
}

void UObjectInteractionBehavior::StartCreativeInteractionOnClient_Implementation()
{
}

void UObjectInteractionBehavior::StartCreativeInteractionOnServer_Implementation()
{
}

void UObjectInteractionBehavior::TickMovementMode_Implementation()
{
}

void UObjectInteractionBehavior::TriggerInteractionBehavior_Implementation()
{
}

void UDeleteObjects::GetDeleteActorsMeshComponents(TArray<UMeshComponent*>& Components)
{
}

void UDeleteObjects::PlayDeleteAnimation()
{
}

void UPlaysetPreview::OnRep_PlaysetToPlace()
{
}

void UPlaysetPreview::ServerSetPreviewLocation_Implementation(const FVector& NewPreviewLocation)
{
}
bool UPlaysetPreview::ServerSetPreviewLocation_Validate(const FVector& NewPreviewLocation)
{
	return true;
}

void UPlaysetPreview::UpdatePreviewMeshScale()
{
}

void UPlaysetPreview::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlaysetPreview, PlaysetToPlace);
}

bool UPossessPropInteraction::CanInteract_Implementation()
{
	return false;
}
