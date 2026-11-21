// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortKismetLibrary.h"

void UFortKismetLibrary::ActivateQuickBarSlot(AFortPlayerPawn* PlayerPawn, EFortQuickBars InQuickBar, int32 Slot, float ActivateDelay, bool bUpdatePreviousFocusedSlot, bool bForceExecution)
{
}

void UFortKismetLibrary::AddActorToClear(UObject* WorldContextObject, ABuildingActor* Building)
{
}

UCameraModifier* UFortKismetLibrary::AddCameraModifierForOwningPlayerController(TSubclassOf<UCameraModifier> InCameraModifierClass, AActor* InActor)
{
	return nullptr;
}

UControllerComponent* UFortKismetLibrary::AddControllerComponent(AController* Controller, TSubclassOf<UControllerComponent> ControllerCompClass)
{
	return nullptr;
}

void UFortKismetLibrary::AddRegenItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* RegenItemDefinition, int32 NumberToGive, bool bNotifyPlayer, bool bResetRegenCooldown)
{
}

void UFortKismetLibrary::AddScoringEvent(AFortPlayerController* Controller, FGameplayTagContainer TargetTags)
{
}

void UFortKismetLibrary::ApplyCharacterCosmetics(UObject* WorldContextObject, TArray<UCustomCharacterPart*> CharacterParts, AFortPlayerState* PlayerState, bool& bSuccess)
{
}

void UFortKismetLibrary::ApplyEventOverrides(const FString& EventSection, bool& bSuccess)
{
}

void UFortKismetLibrary::ApplyGameplayEffectSpecToActorsInRange(UObject* WorldContextObject, const FGameplayEffectSpecHandle& EffectSpecToApply, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, const FVector& SourcePosition, const float Range, const TArray<AActor*>& IgnoredActors, const bool bRequireLOS, UAbilitySystemComponent* InstigatorAbilitySystemComp)
{
}

void UFortKismetLibrary::ApplyGameplayEffectsToActor(AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, const FVector& SourcePos, const bool bRequireLOS, const int32 EffectLevel, UAbilitySystemComponent* InstigatorAbilitySystemComp)
{
}

void UFortKismetLibrary::ApplyGameplayEffectsToActorsInBox(UObject* WorldContextObject, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, const FVector& BoxCenter, const FVector& BoxExtents, const FRotator& BoxOrientation, TArray<AActor*>& IgnoredActors, const bool bRequireLOS, const int32 GameplayEffectLevel, const float DebugLifeTime)
{
}

void UFortKismetLibrary::ApplyGameplayEffectToActorsInRange(UObject* WorldContextObject, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, const FVector& SourcePosition, float Range, TArray<AActor*>& IgnoredActors, const bool bRequireLOS, const int32 GameplayEffectLevel, UAbilitySystemComponent* InstigatorAbilitySystemComp)
{
}

void UFortKismetLibrary::ApplyGlobalEnvironmentDamageToActor(AActor* DamageTargetActor, float EnvironmentDamage, FGameplayTagContainer AdditionalContextTags, TSubclassOf<UGameplayEffect> EnvironmentDamageGE)
{
}

void UFortKismetLibrary::ApplyGlobalEnvironmentGameplayEffect(UObject* WorldContextObject, TSubclassOf<UGameplayEffect> GameplayEffect, int32 GameplayEffectLevel, FGameplayTagContainer AdditionalContextTags)
{
}

FActiveGameplayEffectHandle UFortKismetLibrary::ApplyGlobalEnvironmentGameplayEffectToActor(AActor* EffectTargetActor, TSubclassOf<UGameplayEffect> GameplayEffect, int32 GameplayEffectLevel, FGameplayTagContainer AdditionalContextTags)
{
	return FActiveGameplayEffectHandle();
}

bool UFortKismetLibrary::AreAthenaVehiclesEnabled()
{
	return false;
}

bool UFortKismetLibrary::AreCampaignVehiclesEnabled()
{
	return false;
}

AFortPlayerState* UFortKismetLibrary::AttemptGetPlayerStateForPawn(const AFortPlayerPawn* FortPawn)
{
	return nullptr;
}

TArray<AFortPlayerPawn*> UFortKismetLibrary::AuthorityGetFortPossessedPlayerPawns(UObject* WorldContextObject)
{
	return TArray<AFortPlayerPawn*>();
}

bool UFortKismetLibrary::BoxOverlapActors(const UObject* WorldContextObject, const FTransform& BoxTransform, const FVector& BoxExtent, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors)
{
	return false;
}

bool UFortKismetLibrary::BoxOverlapComponents(const UObject* WorldContextObject, const FTransform& BoxTransform, const FVector& BoxExtent, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ComponentClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<UPrimitiveComponent*>& OutComponents)
{
	return false;
}

void UFortKismetLibrary::BroadcastAbilityImpactAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* Instigator, const FVector& Position, const float Radius, const FName Tag, const bool bSubtractLocalNoise)
{
}

void UFortKismetLibrary::BroadcastAbilitySpinThrustAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* Instigator, const FVector& Position, float Radius, FName Tag)
{
}

void UFortKismetLibrary::BroadcastMessage(UObject* WorldContextObject, const FText& Message)
{
}

bool UFortKismetLibrary::BroadcastPlayerImpactAtLocation(UObject* WorldContextObject, APlayerController* Player, const FVector& Position, float& Loudness, float& Duration, bool bRelativePosition)
{
	return false;
}

void UFortKismetLibrary::BroadcastSound(UObject* WorldContextObject, USoundBase* InSound, float VolumeMultiplier, float PitchMultiplier)
{
}

void UFortKismetLibrary::BroadcastSoundAtLocation(UObject* WorldContextObject, USoundBase* InSound, FVector Location, float VolumeMultiplier, float PitchMultiplier)
{
}

bool UFortKismetLibrary::CanFollowNextOrPreviousTeammate(const APlayerController* OwningControler)
{
	return false;
}

bool UFortKismetLibrary::CanPerformNativeAction(const UFortAbilitySystemComponent* FortAbilitySystem, const FGameplayTag& NativeActionTag)
{
	return false;
}

void UFortKismetLibrary::ChangeTeam(AActor* PlayerToSwitch, AActor* Instigator, uint8 NewTeam, FGameplayTagContainer ChangeTeamTags)
{
}

bool UFortKismetLibrary::CheckHasEnoughResourcesForSmartConsume(int32 ResourceCost, AFortPlayerController* SourcePlayer)
{
	return false;
}

bool UFortKismetLibrary::CheckLineOfSightToActor(const FVector& SourcePos, const AActor* Target, const AActor* Source)
{
	return false;
}

bool UFortKismetLibrary::CheckLineOfSightToActorWithChannel(const FVector& SourcePos, const AActor* Target, ECollisionChannel TargetFilterChannel, const AActor* Source)
{
	return false;
}

bool UFortKismetLibrary::CheckPlayerLineOfSightToPawn(const AFortPlayerPawn* SourcePawn, const AFortPawn* TargetPawn)
{
	return false;
}

void UFortKismetLibrary::ClearDroppableItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bAllowShouldDropItemOverride)
{
}

void UFortKismetLibrary::ClearTutorialHighlights(UObject* WorldContextObject)
{
}

void UFortKismetLibrary::ClientForceFireSelectedWeapon(AFortPlayerPawn* PlayerPawn)
{
}

bool UFortKismetLibrary::CloseActor(AActor* OpenableInterfaceActor, AController* OptionalControllerInstigator)
{
	return false;
}

FVector UFortKismetLibrary::ComputePhysicsAngularVelocity(const FVector& Current, const FVector& Target, const FVector& BackupAxis, const float SpeedCoef, const float DeltaTime)
{
	return FVector();
}

float UFortKismetLibrary::ConvertToGameTime(UObject* WorldContextObject, float InRealTime)
{
	return float();
}

float UFortKismetLibrary::ConvertToRealTime(UObject* WorldContextObject, float InGameTime)
{
	return float();
}

void UFortKismetLibrary::CopyHideElements(const UMaterialInterface* SourceMaterial, UMaterialInstanceDynamic* TargetMID)
{
}

void UFortKismetLibrary::CopyJerseyElements(UMaterialInstanceDynamic* SourceMID, UMaterialInstanceDynamic* TargetMID)
{
}

FFortItemEntry UFortKismetLibrary::CreateItemEntry(const UFortItemDefinition* InItemDefinition, int32 InCount, int32 InLevel)
{
	return FFortItemEntry();
}

AFortPickup* UFortKismetLibrary::CreateTossAmmoPickupForWeaponItemDefinitionAtLocation(UObject* WorldContextObject, const UFortWeaponItemDefinition* WeaponItemDefinition, const FGameplayTagContainer& SourceTags, const FVector& Location, const EFortPickupSourceTypeFlag SourceTypeFlag, const EFortPickupSpawnSource SpawnSource)
{
	return nullptr;
}

void UFortKismetLibrary::CustomHandleActorStreamedInEditor(AActor* SourceActor)
{
}

void UFortKismetLibrary::DeactivateAttachedParticleSystems(const AFortPlayerPawn* PlayerPawn, TArray<UFXSystemComponent*>& FXComponents, bool bOnlyActiveSystems)
{
}

void UFortKismetLibrary::DebugBoxSendToAll(UObject* WorldContextObject, const FVector& Center, const FVector& Extent, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void UFortKismetLibrary::DebugCapsuleSendToAll(UObject* WorldContextObject, const FVector& Center, float HalfHeight, float Radius, const FQuat& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void UFortKismetLibrary::DebugLineSendToAll(UObject* WorldContextObject, const FVector& LineStart, const FVector& LineEnd, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void UFortKismetLibrary::DebugOrientedBoxSendToAll(UObject* WorldContextObject, const FVector& Center, const FVector& Extent, const FRotator& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void UFortKismetLibrary::DebugSphereSendToAll(UObject* WorldContextObject, const FVector& Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void UFortKismetLibrary::DestroyItemInQuickBarSlot(AFortPlayerPawn* PlayerPawn, const UFortItemDefinition* ItemToDestroyFromInventory, FGuid ItemVariantGuid)
{
}

bool UFortKismetLibrary::DeviceSupportsForceFeedback()
{
	return false;
}

void UFortKismetLibrary::DisableTutorialHighlight(UObject* WorldContextObject, FName WidgetName)
{
}

float UFortKismetLibrary::Divide_Int64Int64UsingFloatingPoint(int64 A, int64 B)
{
	return float();
}

bool UFortKismetLibrary::DoesItemConsumeUniqueRangedWeaponAmmo(const UFortItem* Item)
{
	return false;
}

bool UFortKismetLibrary::DoesItemDefinitionConsumeUniqueRangedWeaponAmmo(const UFortItemDefinition* ItemDefinition)
{
	return false;
}

bool UFortKismetLibrary::DoesItemDefinitionHaveGameplayTag(const UFortItemDefinition* ItemDefinition, const FGameplayTag& Tag)
{
	return false;
}

TArray<AFortPickup*> UFortKismetLibrary::DropInstancedLoot(AFortPawn* PawnContext, const FName& LootTierGroup, const TArray<AFortPlayerController*>& RelevantPlayers, bool bAllowCombining)
{
	return TArray<AFortPickup*>();
}

TArray<AFortPickup*> UFortKismetLibrary::DropInstancedLootAtLocation(UObject* WorldContextObject, const FName& LootTierGroup, const TArray<AFortPlayerController*>& RelevantPlayers, bool bAllowCombining, FVector DropLocation, EFortPickupSourceTypeFlag SourceTypeFlag)
{
	return TArray<AFortPickup*>();
}

void UFortKismetLibrary::DropItemByGuid(AController* Controller, const FGuid ItemGuid, const int32 AmountToDrop)
{
}

void UFortKismetLibrary::DumpChildrenComponents(const USceneComponent* ParentComponent, const bool bIncludeAllDescendants)
{
}

void UFortKismetLibrary::EffectContextAddSourceObject(FGameplayEffectContextHandle EffectContext, UObject* Src)
{
}

bool UFortKismetLibrary::EmptyQuickBarSlot(UObject* WorldContextObject, EFortQuickBars QuickBarType, int32 SlotIndex)
{
	return false;
}

void UFortKismetLibrary::EnableTutorialHighlight(UObject* WorldContextObject, FName WidgetName)
{
}

bool UFortKismetLibrary::EqualEqual_UniqueNetIdReplUniqueNetIdRepl(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B)
{
	return false;
}

FFortAbilitySetHandle UFortKismetLibrary::EquipFortAbilitySet(TScriptInterface<IAbilitySystemInterface> AbilitySystemInterfaceActor, UFortAbilitySet* AbilitySet, UObject* OverrideSourceObject)
{
	return FFortAbilitySetHandle();
}

bool UFortKismetLibrary::EquipItemToQuickBarSlot(UObject* WorldContextObject, const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, EFortQuickBars QuickBarType, int32 SlotIndex)
{
	return false;
}

bool UFortKismetLibrary::EvaluateCurveTableRow(FCurveTableRowHandle CurveTableRowHandle, float InXY, float& OutXY, const FString& ContextString)
{
	return false;
}

void UFortKismetLibrary::ExecuteClientEvent(UObject* WorldContextObject, FFortClientEventName EventType, UObject* EventSource, UObject* EventFocus)
{
}

USkeletalMesh* UFortKismetLibrary::ExtractSkeletalMesh(TSubclassOf<AActor> BlueprintClass)
{
	return nullptr;
}

FVector UFortKismetLibrary::ExtractSkeletalMeshScale(TSubclassOf<AActor> BlueprintClass)
{
	return FVector();
}

bool UFortKismetLibrary::FilterSingleTargetActor(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, AActor* TargetActor)
{
	return false;
}

bool UFortKismetLibrary::FilterSingleTargetHitResult(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const FHitResult& HitResult)
{
	return false;
}

TArray<AActor*> UFortKismetLibrary::FilterTargetActorList(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const TArray<AActor*>& ActorsToFilter, bool& bAtLeastOneActorLeft)
{
	return TArray<AActor*>();
}

TArray<FHitResult> UFortKismetLibrary::FilterTargetHitResultList(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const TArray<FHitResult>& HitResultsToFilter, bool& bAtLeastOneActorLeft)
{
	return TArray<FHitResult>();
}

TArray<AActor*> UFortKismetLibrary::FindActorsContainingName(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FString& Name)
{
	return TArray<AActor*>();
}

TArray<UActorComponent*> UFortKismetLibrary::FindAllComponents(const UObject* WorldContextObject, TSubclassOf<UActorComponent> ComponentClass)
{
	return TArray<UActorComponent*>();
}

bool UFortKismetLibrary::FindFirstTagForParentTagChecked(const AActor* TargetActor, const FGameplayTag& ParentTagToCheck, FGameplayTag& OutChildTag)
{
	return false;
}

FVector UFortKismetLibrary::FindGroundLocationAt(UWorld* World, const AActor* IgnoreActor, const FVector& InLocation, float TraceStartZ, float TraceEndZ, FName TraceName)
{
	return FVector();
}

FVector UFortKismetLibrary::FindGroundLocationUsingWorldContextAt(UObject* WorldContextObject, const AActor* IgnoreActor, const FVector& InLocation, float TraceStartZ, float TraceEndZ, FName TraceName)
{
	return FVector();
}

UActorComponent* UFortKismetLibrary::FindOrAddArbitraryComponent(AActor* TargetActor, TSubclassOf<UActorComponent> ComponentClass)
{
	return nullptr;
}

FVector UFortKismetLibrary::FindStaticGroundLocationAt(UWorld* World, const FVector& InLocation, const AActor* IgnoreActor, float TraceStartZ, float TraceEndZ)
{
	return FVector();
}

FVector UFortKismetLibrary::FindStaticGroundLocationUsingWorldContextAt(UObject* WorldContextObject, const FVector& InLocation, const AActor* IgnoreActor, float TraceStartZ, float TraceEndZ)
{
	return FVector();
}

FVector UFortKismetLibrary::FindStaticGroundLocationWithExtentAt(UWorld* World, const FVector& InLocation, const FQuat& ActorRotation, const FVector& ActorExtent, const AActor* IgnoreActor, float TraceStartZ, float TraceEndZ)
{
	return FVector();
}

void UFortKismetLibrary::ForceEnableCustomDepthStencil(bool bForceEnable, UObject* ModifyingObject)
{
}

void UFortKismetLibrary::FortBlueprintLog(const UObject* WorldContextObject, const FString& InString)
{
}

void UFortKismetLibrary::FortShippingLog(UObject* WorldContextObject, const FString& InString, bool bLogAsWarning)
{
}

FGuid UFortKismetLibrary::GenerateGuidFromObject(const UObject* InObject, bool bOnlyStrings)
{
	return FGuid();
}

void UFortKismetLibrary::GetActorCollisionComponentBounds(FVector& OutOrigin, FVector& OutBoxExtent, const AActor* BoundsActor, const bool bIncludeFromChildActors)
{
}

bool UFortKismetLibrary::GetActorPvPTeamIndex(const AActor* Actor, uint8& TeamIndex)
{
	return false;
}

uint8 UFortKismetLibrary::GetActorTeam(const AActor* Actor)
{
	return uint8();
}

AFortTeamInfo* UFortKismetLibrary::GetActorTeamInfo(AActor* Actor)
{
	return nullptr;
}

FBox UFortKismetLibrary::GetActorVisualComponentBounds(const AActor* BoundsActor)
{
	return FBox();
}

AFortAIDirector* UFortKismetLibrary::GetAIDirector(UObject* WorldContextObject)
{
	return nullptr;
}

AFortAIGoalManager* UFortKismetLibrary::GetAIGoalManager(const UObject* WorldContextObject)
{
	return nullptr;
}

AFortPawn* UFortKismetLibrary::GetAimedAtEnemy(const AFortPlayerController* SourcePlayer, const float RectHalfWidth, const float RectHalfHeight, const float Range, const bool bTargetAIPawns)
{
	return nullptr;
}

TArray<AFortPlayerController*> UFortKismetLibrary::GetAllFortPlayerControllers(const UObject* WorldContextObject, const bool bIncludeNonSpectators, const bool bIncludeSpectators)
{
	return TArray<AFortPlayerController*>();
}

void UFortKismetLibrary::GetAllFortPlayerPawns(const UObject* WorldContextObject, TArray<AFortPlayerPawn*>& OutFortPlayerPawns)
{
}

TArray<FAmmoItemState> UFortKismetLibrary::GetAmmoItemDefinitionsFromInventoryWeapons(AFortPlayerController* Controller)
{
	return TArray<FAmmoItemState>();
}

float UFortKismetLibrary::GetAngleDegrees(const FVector& Source, const FVector& Target)
{
	return float();
}

AFortPawn* UFortKismetLibrary::GetBestAimedAtPawnByAngle(const AFortPlayerPawn* SourcePawn, FVector DestOffsetVec, const float MaxAngleInDegree, const float Range, const bool bTargetAIPawns, EFortTeamAffiliation::Type TeamAffiliationRequirement)
{
	return nullptr;
}

float UFortKismetLibrary::GetBuildingHealthPercentage(const ABuildingActor* BuildingActor)
{
	return float();
}

void UFortKismetLibrary::GetBuildingStructuralSupportSystem(UObject* WorldContextObject, UBuildingStructuralSupportSystem*& BuildingStructuralSupportSystem)
{
}

void UFortKismetLibrary::GetCalendarEventInformation(UObject* WorldContextObject, const FString& EventName, bool& bIsEventActive, FTimespan& TimeSinceBegin, FTimespan& TimeUntilEnd, float& TimeSpanRatio)
{
}

bool UFortKismetLibrary::GetCameraComponentAdditiveOffset(FTransform& OutAdditiveTransformOffset, float& OutAdditiveFOVOffset, const UCameraComponent* CameraComponent)
{
	return false;
}

bool UFortKismetLibrary::GetCameraLookHitResult(FHitResult& OutHitResult, const AFortPlayerController* PlayerController, const float CameraForwardTraceDistance, const bool bTraceComplex)
{
	return false;
}

AActor* UFortKismetLibrary::GetClosestActorFromArray(const AActor* Actor, const TArray<AActor*>& ArrayOfActors)
{
	return nullptr;
}

ABuildingSMActor* UFortKismetLibrary::GetClosestBuildingActorFromArray(const AActor* Actor, const TArray<ABuildingSMActor*>& ArrayOfBuildings)
{
	return nullptr;
}

AFortPlayerPawn* UFortKismetLibrary::GetClosestFortPlayerPawn(const UObject* WorldContextObject, const FVector& Position)
{
	return nullptr;
}

AFortPlayerPawn* UFortKismetLibrary::GetClosestFortPlayerPawnByTeamAffiliation(const UObject* WorldContextObject, const FVector& Position, const AActor* TeamAffiliationActor, const EFortTeamAffiliation::Type TeamAffiliation)
{
	return nullptr;
}

TScriptInterface<IFortTimeOfDayManagerInterface> UFortKismetLibrary::GetContextualTimeOfDayManager(UObject* WorldContextObject)
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

AController* UFortKismetLibrary::GetControllerFromActor(AActor* Actor)
{
	return nullptr;
}

void UFortKismetLibrary::GetControllerObjectiveStatSourceTags(const AController* Controller, FGameplayTagContainer& OutTags, bool bIsInitiator)
{
}

void UFortKismetLibrary::GetControllerSpecialStatSourceTags(const AController* Controller, FGameplayTagContainer& InOutTags, const AController* InitiatorPC, bool bNeedToFetchClassTags, bool bInitiatorHadFriendHelp)
{
}

EAthenaWinCondition UFortKismetLibrary::GetCurrentAthenaWinCondition(const UObject* WorldContextObject)
{
	return EAthenaWinCondition();
}

EFortDayPhase UFortKismetLibrary::GetCurrentDayPhase(UObject* WorldContextObject)
{
	return EFortDayPhase();
}

int32 UFortKismetLibrary::GetCurrentSafeZonePhase(UObject* WorldContextObject)
{
	return int32();
}

FString UFortKismetLibrary::GetDebugStringForUniqueId(const FUniqueNetIdRepl& UniqueID)
{
	return FString();
}

float UFortKismetLibrary::GetDefaultAbsoluteTimeOfDaySpeed(UObject* WorldContextObject)
{
	return float();
}

FRotator UFortKismetLibrary::GetDirectionActorToActor(AActor* SourceActor, AActor* TargetActor)
{
	return FRotator();
}

FVector UFortKismetLibrary::GetEffectDirection(FGameplayEffectContextHandle EffectContext)
{
	return FVector();
}

FGameplayTagContainer UFortKismetLibrary::GetFactionTagContainerForActor(const AActor* Actor)
{
	return FGameplayTagContainer();
}

AFortPlayerController* UFortKismetLibrary::GetFirstLocalFortPlayerController(const UObject* WorldContextObject, bool bIncludeNonSpectators, bool bIncludeSpectators)
{
	return nullptr;
}

float UFortKismetLibrary::GetFloatHoursUntilDayPhase(UObject* WorldContextObject, EFortDayPhase DayPhase)
{
	return float();
}

UFortGameUserSettings* UFortKismetLibrary::GetFortGameUserSettings()
{
	return nullptr;
}

void UFortKismetLibrary::GetFortPawnsInRange(UObject* WorldContextObject, const FVector& SourcePosition, const float Range, const bool bDo2DCheck, TArray<AFortPawn*>& OutFortPawns)
{
}

EPhysicalSurface UFortKismetLibrary::GetFortPhysicalSurface(const FHitResult& Hit)
{
	return EPhysicalSurface();
}

AFortPlayerController* UFortKismetLibrary::GetFortPlayerControllerFromActor(AActor* Actor)
{
	return nullptr;
}

TArray<AFortPlayerPawn*> UFortKismetLibrary::GetFortPlayerPawns(const UObject* WorldContextObject)
{
	return TArray<AFortPlayerPawn*>();
}

void UFortKismetLibrary::GetFortPlayerPawnsInRange(UObject* WorldContextObject, const FVector& SourcePosition, const float Range, const bool bDo2DCheck, TArray<AFortPlayerPawn*>& OutFortPlayerPawns)
{
}

AFortWorldSettings* UFortKismetLibrary::GetFortWorldSettingsInEditor(UObject* WorldContextObject)
{
	return nullptr;
}

bool UFortKismetLibrary::GetGameContextGameplayTags(UObject* WorldContextObject, FGameplayTagContainer& OutGameContextGameplayTags)
{
	return false;
}

AFortGameStateAthena* UFortKismetLibrary::GetGameStateAthena(const UObject* WorldContextObject)
{
	return nullptr;
}

AFortGameStateAthena* UFortKismetLibrary::GetGameStateAthenaFromContext(const UObject* WorldContextObject)
{
	return nullptr;
}

void UFortKismetLibrary::GetGenericDamageSurfaceTypeTag(const AActor* Actor, FGameplayTag& OutSurfaceTypeTag)
{
}

TScriptInterface<IFortTimeOfDayManagerInterface> UFortKismetLibrary::GetGlobalTimeOfDayManager(UObject* WorldContextObject)
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

AActor* UFortKismetLibrary::GetHeldObjectAttachedToPlayer(const AFortPlayerPawn* FortPawn)
{
	return nullptr;
}

UFortHeldObjectComponent* UFortKismetLibrary::GetHeldObjectComponentAttachedToPlayer(const AFortPlayerPawn* FortPawn)
{
	return nullptr;
}

AFortPlayerPawn* UFortKismetLibrary::GetHeldObjectsOwningPlayer(const AActor* HeldObject)
{
	return nullptr;
}

float UFortKismetLibrary::GetHostilityPercentage(UObject* WorldContextObject)
{
	return float();
}

int32 UFortKismetLibrary::GetHoursUntilDayPhase(UObject* WorldContextObject, EFortDayPhase DayPhase)
{
	return int32();
}

FString UFortKismetLibrary::GetHumanReadableName(AActor* Actor)
{
	return FString();
}

void UFortKismetLibrary::GetImpulseData(FGameplayEffectContextHandle EffectContext, FVector& ImpulseDirection, float& KnockbackMagnitude, float& KnockbackZAngle)
{
}

const UFortItem* UFortKismetLibrary::GetInventoryItemWithGuid(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FGuid ItemGuid)
{
	return nullptr;
}

bool UFortKismetLibrary::GetIsBroadcastClient(UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::GetIsPlayingReplay(UObject* WorldContextObject)
{
	return false;
}

UFortItemDefinition* UFortKismetLibrary::GetItemDefinitionFromItemQuantityPair(const FFortItemQuantityPair& ItemQuantityPair)
{
	return nullptr;
}

int32 UFortKismetLibrary::GetItemQuantityOnInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, const FGuid ItemVariantGuid)
{
	return int32();
}

int32 UFortKismetLibrary::GetItemQuantityOnPlayerByGUID(AFortPlayerController* PlayerController, const FGuid& ItemGuid)
{
	return int32();
}

bool UFortKismetLibrary::GetLevelViewportCameraInfo(UObject* WorldContextObject, FVector& CameraLocation, FRotator& CameraRotation)
{
	return false;
}

ELicensedAudioTreatment UFortKismetLibrary::GetLicensedAudioTreatment(const UObject* WorldContextObject)
{
	return ELicensedAudioTreatment();
}

TArray<AFortPlayerController*> UFortKismetLibrary::GetLocalFortPlayerControllers(const UObject* WorldContextObject, const bool bIncludeNonSpectators, const bool bIncludeSpectators)
{
	return TArray<AFortPlayerController*>();
}

int32 UFortKismetLibrary::GetLootLevel(UObject* WorldContextObject)
{
	return int32();
}

void UFortKismetLibrary::GetMatchmakingDifficultyRangeFromDifficultyInfo(const FGameDifficultyInfo& DifficultyInfo, float& OutMinDifficulty, float& OutMaxDifficulty)
{
}

float UFortKismetLibrary::GetMatchTime(const UObject* WorldContextObject)
{
	return float();
}

bool UFortKismetLibrary::GetMeleeWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortMeleeWeaponStats& OutRow)
{
	return false;
}

UMaterialInstanceDynamic* UFortKismetLibrary::GetMIDForSkeletalMeshComponent(USkeletalMeshComponent* SkeletalMeshComponent, int32 ElementIndex)
{
	return nullptr;
}

AFortMusicManager* UFortKismetLibrary::GetMusicManager(UObject* WorldContextObject)
{
	return nullptr;
}

ANavigationData* UFortKismetLibrary::GetNavigationDataForActor(AActor* Actor)
{
	return nullptr;
}

int32 UFortKismetLibrary::GetNumActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass)
{
	return int32();
}

int32 UFortKismetLibrary::GetNumberOfRegisteredPlayers(UObject* WorldContextObject)
{
	return int32();
}

bool UFortKismetLibrary::GetNumericCVar(const FString& CVar, float& OutValue)
{
	return false;
}

float UFortKismetLibrary::GetOceanTotalHeight(const UObject* WorldContextObject)
{
	return float();
}

bool UFortKismetLibrary::GetPawnStatsRow(FDataTableRowHandle DataTableRowHandle, FFortPawnStats& OutRow)
{
	return false;
}

int64 UFortKismetLibrary::GetPhysicalMemoryMB()
{
	return int64();
}

FVector UFortKismetLibrary::GetPlayerAimPoint(const AFortPlayerController* SourcePlayer, const float MaxRange, const TArray<AActor*>& IgnoredActors, const bool NoTrace)
{
	return FVector();
}

FHitResult UFortKismetLibrary::GetPlayerAimPointHit(const AFortPlayerController* SourcePlayer, const float MaxRange, const TArray<AActor*>& IgnoredActors)
{
	return FHitResult();
}

UFortRegisteredPlayerInfo* UFortKismetLibrary::GetPlayerInfoFromUniqueID(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID)
{
	return nullptr;
}

FString UFortKismetLibrary::GetPlayerNameSafe(const AActor* Actor)
{
	return FString();
}

FString UFortKismetLibrary::GetPlayerOrObjectNameSafe(const AActor* InActor)
{
	return FString();
}

bool UFortKismetLibrary::GetPlaylistAllowsTeamSwitching(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::GetPlaylistUsesCustomCharacterParts(const UObject* WorldContextObject)
{
	return false;
}

EFortDayPhase UFortKismetLibrary::GetPreviousDayPhase(UObject* WorldContextObject)
{
	return EFortDayPhase();
}

UGameplayAbility* UFortKismetLibrary::GetPrimaryAbilityInstanceOfAbilitySystemComponent(UFortAbilitySystemComponent* AbilitySystemComponent, TSubclassOf<UFortGameplayAbility> AbilityClass)
{
	return nullptr;
}

UGameplayAbility* UFortKismetLibrary::GetPrimaryInstance(const FGameplayAbilitySpec& Spec)
{
	return nullptr;
}

void UFortKismetLibrary::GetProjectileTrajectoryData(FFortProjectileTrajectoryData& TrajectoryData, const AActor* Instigator, const TSubclassOf<AActor> ProjectileClass, const float DefaultSpeed, const float DefaultGravityScale)
{
}

FText UFortKismetLibrary::GetRandomSurvivorName(UObject* WorldContextObject, EFortDisplayGender::Type Gender, bool bRemoveFromList)
{
	return FText();
}

int32 UFortKismetLibrary::GetRandomWeightedIndex(const TArray<float>& InWeights)
{
	return int32();
}

bool UFortKismetLibrary::GetRangedWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortRangedWeaponStats& OutRow)
{
	return false;
}

float UFortKismetLibrary::GetRealMatchTime(const UObject* WorldContextObject)
{
	return float();
}

int32 UFortKismetLibrary::GetResourceMaxStackSize(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType)
{
	return int32();
}

bool UFortKismetLibrary::GetSafeZoneLocation(UObject* WorldContextObject, int32 SafeZoneIndex, FVector& OutLocation)
{
	return false;
}

UFortSeasonalEventManager* UFortKismetLibrary::GetSeasonalEventManager(const UObject* WorldContextObject)
{
	return nullptr;
}

float UFortKismetLibrary::GetServerWorldRealTimeSeconds(const UObject* WorldContextObject)
{
	return float();
}

float UFortKismetLibrary::GetServerWorldTimeSeconds(const UObject* WorldContextObject)
{
	return float();
}

bool UFortKismetLibrary::GetShowTeamSelectButton(const UObject* WorldContextObject)
{
	return false;
}

FString UFortKismetLibrary::GetSoftPtrAssetName(const TSoftObjectPtr<UObject> Asset)
{
	return FString();
}

FDataTableRowHandle UFortKismetLibrary::GetSpecialActorInputActionDataTableRow(UObject* WorldContextObject)
{
	return FDataTableRowHandle();
}

void UFortKismetLibrary::GetStaticMeshComponentsForClass(const TSubclassOf<AActor> Class, TArray<UStaticMeshComponent*>& OutStaticMeshComponents)
{
}

void UFortKismetLibrary::GetStaticMeshesForClass(const TSubclassOf<AActor> Class, TArray<UStaticMesh*>& OutStaticMeshes)
{
}

float UFortKismetLibrary::GetStunTime(FGameplayEffectContextHandle EffectContext)
{
	return float();
}

ESubGame UFortKismetLibrary::GetSubGame(const UObject* WorldContextObject)
{
	return ESubGame();
}

EFortTeamAffiliation::Type UFortKismetLibrary::GetTeamAffiliation(const AActor* ActorA, const AActor* ActorB)
{
	return EFortTeamAffiliation::Type();
}

EFortTeamAffiliation::Type UFortKismetLibrary::GetTeamAffiliationBetweenTeams(uint8 TeamA, uint8 TeamB)
{
	return EFortTeamAffiliation::Type();
}

EFortTeamAffiliation::Type UFortKismetLibrary::GetTeamAffiliationForActorToLocalPlayer(const AActor* Actor, bool bIncludeNonSpectators, bool bIncludeSpectators)
{
	return EFortTeamAffiliation::Type();
}

EFortTeamAffiliation::Type UFortKismetLibrary::GetTeamAffiliationToLocalPlayer(UObject* WorldContextObject, uint8 Team, bool bIncludeNonSpectators, bool bIncludeSpectators)
{
	return EFortTeamAffiliation::Type();
}

AFortTeamInfo* UFortKismetLibrary::GetTeamInfo(UObject* WorldContextObject, uint8 Team)
{
	return nullptr;
}

AFortThreatVisualsManager* UFortKismetLibrary::GetThreatVisualsManager(UObject* WorldContextObject)
{
	return nullptr;
}

float UFortKismetLibrary::GetTimeDayPhaseBegins(UObject* WorldContextObject, EFortDayPhase DayPhase)
{
	return float();
}

float UFortKismetLibrary::GetTimeOfDay(UObject* WorldContextObject)
{
	return float();
}

float UFortKismetLibrary::GetTimeOfDaySpeed(UObject* WorldContextObject)
{
	return float();
}

float UFortKismetLibrary::GetTimeUntilInRealTimeSeconds(UObject* WorldContextObject, float GameTime)
{
	return float();
}

bool UFortKismetLibrary::GetTooltipDescription(UObject* WorldContextObject, const UObject* ObjectToDescribe, FGameplayTag Tag, const UFortTooltipContext* Context, TArray<FText>& Description, bool bSummaryTooltip)
{
	return false;
}

bool UFortKismetLibrary::GetTooltipDescriptionFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, FGameplayTag Tag, const UFortTooltipContext* Context, TArray<FText>& Description, bool bSummaryTooltip)
{
	return false;
}

bool UFortKismetLibrary::GetTooltipNumericValue(UObject* WorldContextObject, const UObject* ObjectToDescribe, FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, float& Value)
{
	return false;
}

bool UFortKismetLibrary::GetTooltipNumericValueFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, float& Value)
{
	return false;
}

bool UFortKismetLibrary::GetTooltipTextFromToken(UObject* WorldContextObject, const UObject* ObjectToDescribe, const FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, FText& OutText)
{
	return false;
}

bool UFortKismetLibrary::GetTooltipTextFromTokenFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, const FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, FText& OutText)
{
	return false;
}

bool UFortKismetLibrary::GetTrapStatsRow(FDataTableRowHandle DataTableRowHandle, FFortTrapStats& OutRow)
{
	return false;
}

float UFortKismetLibrary::GetUnmodifiedDamage(FGameplayEffectContextHandle EffectContext)
{
	return float();
}

UFortWeaponItemDefinition* UFortKismetLibrary::GetUpgradedWeaponItemFromTable(UFortWeaponItemDefinition* ItemToUpgrade, EFortWeaponUpgradeDirection UpgradeDirection)
{
	return nullptr;
}

UFortWeaponItemDefinition* UFortKismetLibrary::GetUpgradedWeaponItemVerticalToRarity(const UFortWeaponItemDefinition* ItemToUpgrade, EFortRarity NewRarity)
{
	return nullptr;
}

bool UFortKismetLibrary::GetWeaponDurabilityByRarityStatsRow(FDataTableRowHandle DataTableRowHandle, FFortWeaponDurabilityByRarityStats& OutRow)
{
	return false;
}

bool UFortKismetLibrary::GetWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortBaseWeaponStats& OutRow)
{
	return false;
}

const UFortWorldItem* UFortKismetLibrary::GiveItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive, bool bNotifyPlayer, int32 ItemLevel, int32 PickupInstigatorHandle, bool bUseItemPickupAnalyticEvent, int32 WeaponAmmoOverride)
{
	return nullptr;
}

const UFortWorldItem* UFortKismetLibrary::GiveItemToInventoryOwnerWithParams(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive, const FGiveInventoryItemParams& Params)
{
	return nullptr;
}

bool UFortKismetLibrary::HasMultipleVisibleRewards(const FFortRewardInfo& RewardInfo)
{
	return false;
}

bool UFortKismetLibrary::HasRewards(const FFortRewardInfo& RewardInfo)
{
	return false;
}

bool UFortKismetLibrary::HasSelectableRewards(const FFortRewardInfo& RewardInfo)
{
	return false;
}

void UFortKismetLibrary::HideTutorialWidget(UObject* WorldContextObject, FName WidgetName)
{
}

int32 UFortKismetLibrary::IncrementAnalyticMatchCount(const UObject* WorldContextObject, const EAnalyticMatchCounts MatchCountID, const int32 AmountToAdd)
{
	return int32();
}

bool UFortKismetLibrary::InEditor(UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::InEditorOrPIE(UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsActorInDataLayerInstance(const AActor* Actor, const UDataLayerInstance* DataLayerInstance)
{
	return false;
}

bool UFortKismetLibrary::IsActorSubmergedInOcean(const AActor* Actor)
{
	return false;
}

bool UFortKismetLibrary::IsActorWithinGoldenPOI(const UObject* WorldContextObject, const AActor* InActor)
{
	return false;
}

bool UFortKismetLibrary::IsAssetNull(TSoftObjectPtr<UObject> Asset)
{
	return false;
}

bool UFortKismetLibrary::IsBoundsInAnyView(const UObject* WorldContextObject, const FBoxSphereBounds& Bounds, const FVector& Location, float BoundsScalar)
{
	return false;
}

bool UFortKismetLibrary::IsBoxOverlappingKillVolume(UObject* WorldContextObject, const FVector& Location, const FVector& BoxExtent)
{
	return false;
}

bool UFortKismetLibrary::IsCellConnection()
{
	return false;
}

bool UFortKismetLibrary::IsCompetitivePlaylist(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsConsolePlatform()
{
	return false;
}

bool UFortKismetLibrary::IsCosmeticObjectDisplayedAsPreview(const UObject* CosmeticObject)
{
	return false;
}

bool UFortKismetLibrary::IsCosmeticObjectDisplayedInFrontendContext(const UObject* CosmeticObject)
{
	return false;
}

bool UFortKismetLibrary::IsCreativeOrPlaygroundModePlaylist(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsCreativeRoyalePlaylist(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsCriticalHit(FGameplayEffectContextHandle EffectContext)
{
	return false;
}

bool UFortKismetLibrary::IsCurveTableRowValid(const FCurveTableRowHandle& CurveTableRowHandle, const FString& ContextString)
{
	return false;
}

bool UFortKismetLibrary::IsDiceCritical(FGameplayEffectContextHandle EffectContext)
{
	return false;
}

bool UFortKismetLibrary::IsEnvQueryResultValid(const FEnvQueryResult Result, FString& OutDebugString)
{
	return false;
}

bool UFortKismetLibrary::IsFatalHit(FGameplayEffectContextHandle EffectContext)
{
	return false;
}

bool UFortKismetLibrary::IsFullBodyHit(FGameplayEffectContextHandle EffectContext)
{
	return false;
}

bool UFortKismetLibrary::IsHeldObjectBeingHeld(const AActor* HeldObject)
{
	return false;
}

bool UFortKismetLibrary::IsItemDefinitionAnAbilityOrVehcileWeapon(const UFortItemDefinition* ItemDefinition)
{
	return false;
}

bool UFortKismetLibrary::IsItemDefRandomCustomizationSelector(const UFortItemDefinition* InItemDef)
{
	return false;
}

bool UFortKismetLibrary::IsLocationInSafeZone(UObject* WorldContextObject, const FVector& Location)
{
	return false;
}

bool UFortKismetLibrary::IsMobileGame(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsMobilePlatform()
{
	return false;
}

bool UFortKismetLibrary::IsNavigationDataBuildInProgress(ANavigationData* NavigationData)
{
	return false;
}

bool UFortKismetLibrary::IsPapayaPlaylist(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsPhoneGame()
{
	return false;
}

bool UFortKismetLibrary::IsRunningNoMCP()
{
	return false;
}

bool UFortKismetLibrary::IsSpatialGameplayExperience(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsTabletGame()
{
	return false;
}

bool UFortKismetLibrary::IsUsingBattlEye()
{
	return false;
}

bool UFortKismetLibrary::IsValid(const FAttributeInfo& AttributeInfo)
{
	return false;
}

bool UFortKismetLibrary::IsValid_UniqueNetIdRepl(const FUniqueNetIdRepl& InUniqueNetIdRepl)
{
	return false;
}

bool UFortKismetLibrary::IsVkEditPlaylist(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsXPSystemEnabled(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::IsXPSystemEnabledForWorld(const UWorld* World)
{
	return false;
}

TArray<UObject*> UFortKismetLibrary::JonLHack_GetAllObjectsOfClassFromPath(const FString& Path, UClass* Class, bool bIncludeClassObjects)
{
	return TArray<UObject*>();
}

void UFortKismetLibrary::K2_CycleBuildingMaterial(AFortPlayerController* Controller, bool bBroadcast, bool bDoUIFeedback, bool bHonorAutoSwitch)
{
}

bool UFortKismetLibrary::K2_DoesInventoryOwnerHaveItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const TArray<EFortItemType>& ExcludedItemTypes)
{
	return false;
}

FVector UFortKismetLibrary::K2_GetClosestAxisXY(FVector InVector)
{
	return FVector();
}

EFortResourceType::Type UFortKismetLibrary::K2_GetCurrentResourceType(AFortPlayerController* Controller)
{
	return EFortResourceType::Type();
}

int32 UFortKismetLibrary::K2_GetInventorySpace(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner)
{
	return int32();
}

int32 UFortKismetLibrary::K2_GetItemQuantityOnPlayer(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid)
{
	return int32();
}

int32 UFortKismetLibrary::K2_GetNumAvailableBuildingResources(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType)
{
	return int32();
}

int32 UFortKismetLibrary::K2_GetOverflowCountIfItemWasAddedToInventory(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FFortItemEntry& ItemEntry)
{
	return int32();
}

UFortResourceItemDefinition* UFortKismetLibrary::K2_GetResourceItemDefinition(const EFortResourceType::Type ResourceType)
{
	return nullptr;
}

void UFortKismetLibrary::K2_GiveBuildingResource(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount)
{
}

void UFortKismetLibrary::K2_GiveItemToAllPlayers(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive, bool bNotifyPlayer)
{
}

void UFortKismetLibrary::K2_GiveItemToPlayer(AFortPlayerController* PlayerController, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive, bool bNotifyPlayer)
{
}

bool UFortKismetLibrary::K2_HasBuildingResourcesAvailable(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount)
{
	return false;
}

int32 UFortKismetLibrary::K2_PayBuildingResourceCost(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount)
{
	return int32();
}

int32 UFortKismetLibrary::K2_RemoveFortItemFromPlayer(AFortPlayerController* PlayerController, UFortItem* Item, int32 AmountToRemove, bool bForceRemoval)
{
	return int32();
}

void UFortKismetLibrary::K2_RemoveItemFromAllPlayers(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 AmountToRemove)
{
}

int32 UFortKismetLibrary::K2_RemoveItemFromPlayer(AFortPlayerController* PlayerController, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 AmountToRemove, bool bForceRemoval)
{
	return int32();
}

int32 UFortKismetLibrary::K2_RemoveItemFromPlayerByGuid(AFortPlayerController* PlayerController, FGuid ItemGuid, int32 AmountToRemove, bool bForceRemoval)
{
	return int32();
}

int32 UFortKismetLibrary::K2_RemoveItemsFromPlayerByIntStateValue(AFortPlayerController* PlayerController, EFortItemEntryState::Type StateType, int32 StateValue, bool bForceRemoval)
{
	return int32();
}

int32 UFortKismetLibrary::K2_RemoveItemsFromPlayerByNameStateValue(AFortPlayerController* PlayerController, EFortItemEntryState::Type StateType, FName StateValue, bool bForceRemoval)
{
	return int32();
}

void UFortKismetLibrary::K2_SetCurrentResourceType(AFortPlayerController* Controller, EFortResourceType::Type NewMaterial)
{
}

AFortPickup* UFortKismetLibrary::K2_SpawnPickupInWorld(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, int32 PickupInstigatorHandle, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

AFortPickup* UFortKismetLibrary::K2_SpawnPickupInWorldWithClass(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, TSubclassOf<AFortPickup> PickupClass, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, int32 PickupInstigatorHandle, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

AFortPickup* UFortKismetLibrary::K2_SpawnPickupInWorldWithClassAndItemEntry(UObject* WorldContextObject, const FFortItemEntry& ItemEntry, TSubclassOf<AFortPickup> PickupClass, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

AFortPickup* UFortKismetLibrary::K2_SpawnPickupInWorldWithClassAndLevel(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 WorldLevel, TSubclassOf<AFortPickup> PickupClass, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, int32 PickupInstigatorHandle, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

AFortPickup* UFortKismetLibrary::K2_SpawnPickupInWorldWithLevel(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 WorldLevel, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, int32 PickupInstigatorHandle, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

TArray<AFortPickup*> UFortKismetLibrary::K2_SpawnPickupInWorldWithLootTier(UObject* WorldContextObject, FName LootTierName, FVector Position, int32 OverrideMaxStackCount, AActor* OptionalASCInterface, bool bToss, bool bTossWithVelocity, FVector TossVelocity, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, int32 LootWorldLevel)
{
	return TArray<AFortPickup*>();
}

void UFortKismetLibrary::KeepCGPathOptimizations(const AController* RequestedBy, int64 ExpectedBudget, float Duration)
{
}

void UFortKismetLibrary::MakeAllPlayersTalkToSelf(UObject* WorldContextObject, FLatentActionInfo LatentInfo, USoundBase* Audio, float Delay, bool bInterruptCurrentLine, bool bCanBeInterrupted, bool bCanCue, EFortFeedbackBroadcastFilter BroadcastFilter, bool bLatent)
{
}

EFortBuildingState::Type UFortKismetLibrary::MakeBuildingState(EFortBuildingState::Type Value)
{
	return EFortBuildingState::Type();
}

EFortDayPhase UFortKismetLibrary::MakeDayNightPhase(EFortDayPhase Value)
{
	return EFortDayPhase();
}

FFortGameplayEffectContainerSpec UFortKismetLibrary::MakeGameplayEffectContainerSpecFromAbility(const FFortGameplayEffectContainer& EffectContainer, UGameplayAbility* Ability, int32 GameplayEffectLevel)
{
	return FFortGameplayEffectContainerSpec();
}

FFortGameplayEffectContainerSpec UFortKismetLibrary::MakeGameplayEffectContainerSpecFromAbilityComponent(const FFortGameplayEffectContainer& EffectContainer, UAbilitySystemComponent* AbilityComp, int32 GameplayEffectLevel)
{
	return FFortGameplayEffectContainerSpec();
}

EFortMovementStyle::Type UFortKismetLibrary::MakeMovementStyle(EFortMovementStyle::Type Value)
{
	return EFortMovementStyle::Type();
}

EFortResourceType::Type UFortKismetLibrary::MakeResourceType(EFortResourceType::Type Value)
{
	return EFortResourceType::Type();
}

EFortWeaponCoreAnimation::Type UFortKismetLibrary::MakeWeaponCoreAnimation(EFortWeaponCoreAnimation::Type Value)
{
	return EFortWeaponCoreAnimation::Type();
}

FVector UFortKismetLibrary::NormalizedAngleInDegreesToVector(float A)
{
	return FVector();
}

bool UFortKismetLibrary::NotEqual_UniqueNetIdReplUniqueNetIdRepl(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B)
{
	return false;
}

void UFortKismetLibrary::NotifyProjectileThrown(TSubclassOf<AFortProjectileBase> ProjClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, float Speed)
{
}

bool UFortKismetLibrary::OnSameSquad(const AFortPlayerPawnAthena* PlayerPawnA, const AFortPlayerPawnAthena* PlayerPawnB)
{
	return false;
}

bool UFortKismetLibrary::OnSameTeam(const AActor* ActorA, const AActor* ActorB)
{
	return false;
}

bool UFortKismetLibrary::OpenActor(AActor* OpenableInterfaceActor, AController* OptionalControllerInstigator, bool bRequestFastOpen)
{
	return false;
}

float UFortKismetLibrary::PackHSVToFloat(float Hue, float Saturation, float Value)
{
	return float();
}

float UFortKismetLibrary::PackLinearColorHSVToFloat(const FLinearColor& LinearColor)
{
	return float();
}

bool UFortKismetLibrary::PickLootDrops(UObject* WorldContextObject, TArray<FFortItemEntry>& OutLootToDrop, const FName TierGroupName, const int32 WorldLevel, const int32 ForcedLootTier)
{
	return false;
}

bool UFortKismetLibrary::PickLootDropsWithNamedWeights(UObject* WorldContextObject, TArray<FFortItemEntry>& OutLootToDrop, const FName TierGroupName, const int32 WorldLevel, const TMap<FName, float>& NamedWeightsMap, const int32 ForcedLootTier)
{
	return false;
}

void UFortKismetLibrary::PlayLocalForceFeedbackAtLocation(UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FVector Location, float Radius, FName Tag)
{
}

void UFortKismetLibrary::PlayLocalForceFeedbackAtLocationMulti(UObject* WorldContextObject, UForceFeedbackEffect* NearForceFeedbackEffect, UForceFeedbackEffect* FarForceFeedbackEffect, FVector Location, float InnerRadius, float OuterRadius, FName Tag)
{
}

void UFortKismetLibrary::ProfilerBookmark(const FString& BookmarkStr)
{
}

FVector UFortKismetLibrary::PushOffHitLocation(AActor* RequestedBy, const FHitResult& Hit, float Distance)
{
	return FVector();
}

FTransform UFortKismetLibrary::PushOffTransformByHitLocation(AActor* RequestedBy, const FTransform& InTransform, const FHitResult& Hit, float Distance)
{
	return FTransform();
}

bool UFortKismetLibrary::RandomGroundLocationInCircle(UObject* WorldContextObject, const FVector& CircleCenter, float CircleRadius, const AActor* TraceIgnoreActor, float TraceStartZ, float TraceEndZ, float TraceRadius, FCollisionProfileName TraceProfile, FVector& OutLocation)
{
	return false;
}

FVector2D UFortKismetLibrary::RandPointInDonut(const float& InnerCircleRadius, const float& OuterCircleRadius)
{
	return FVector2D();
}

FVector2D UFortKismetLibrary::RandUniformPointInDonut(const float& InnerCircleRadius, const float& OuterCircleRadius)
{
	return FVector2D();
}

bool UFortKismetLibrary::ReadRenderTargetToBoolArray(UObject* WorldContextObject, UTextureRenderTarget2D* TextureRenderTarget, float Threshold, TArray<bool>& OutBoolArray, bool bDebugPrintToLog)
{
	return false;
}

void UFortKismetLibrary::ReduceDroppableResources(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const float ReductionPercentage)
{
}

void UFortKismetLibrary::RegisterComponent(UActorComponent* InComponent)
{
}

void UFortKismetLibrary::RegisterDayPhaseHitCallback(UObject* Object, const FString& FunctionName, EFortDayPhase Phase, bool bRecurring, bool bBlockTriggeringThisCycle)
{
}

void UFortKismetLibrary::RegisterDayTimeHitCallback(UObject* Object, const FString& FunctionName, float TimeInHours, bool bRecurring, bool bBlockTriggeringThisCycle)
{
}

void UFortKismetLibrary::RegisterGridFoundation(ABuildingFoundation* BuildingFoundation)
{
}

void UFortKismetLibrary::RemoveActorsOfClassFromBuildingSMActorArray(const TArray<ABuildingSMActor*>& ArrayToRemoveClassFrom, TSubclassOf<ABuildingSMActor> ClassToRemove, TArray<ABuildingSMActor*>& ArrayWithClassRemoved)
{
}

void UFortKismetLibrary::RemoveArbitraryComponent(AActor* TargetActor, TSubclassOf<UActorComponent> ComponentClass)
{
}

void UFortKismetLibrary::RemoveControllerComponent(AController* Controller, TSubclassOf<UControllerComponent> ControllerCompClass)
{
}

void UFortKismetLibrary::RemoveEventOverrides(const FString& EventSection, bool& bSuccess)
{
}

void UFortKismetLibrary::RemoveGlobalEnvironmentGameplayEffect(UObject* WorldContextObject, TSubclassOf<UGameplayEffect> GameplayEffect)
{
}

void UFortKismetLibrary::RemoveItemFromInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid)
{
}

void UFortKismetLibrary::RemoveNonResourceDroppableItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner)
{
}

FFortGameplayEffectContainer UFortKismetLibrary::ReplaceHalfExtentsInGameplayEffectContainer(FFortGameplayEffectContainer EffectContainer, const FVector& NewHalfExtents)
{
	return FFortGameplayEffectContainer();
}

FFortGameplayEffectContainer UFortKismetLibrary::ReplaceRangeInGameplayEffectContainer(FFortGameplayEffectContainer EffectContainer, const FScalableFloat& NewRange)
{
	return FFortGameplayEffectContainer();
}

AFortPlayerState* UFortKismetLibrary::ResolvePlayerStateFromContextualObjects(TArray<UObject*> Objects)
{
	return nullptr;
}

FVector UFortKismetLibrary::RotateVectorTowardVector(const FVector& Source, const FVector& Target, const float Degrees)
{
	return FVector();
}

FRotator UFortKismetLibrary::RotatorLerpWithAxisSpeeds(const FRotator& A, const FRotator& B, const FRotator& AxisSpeeds, const float DeltaSeconds)
{
	return FRotator();
}

void UFortKismetLibrary::ScriptEnsureIsValid(const FString& Message, UObject* Object)
{
}

void UFortKismetLibrary::ScriptError(const FString& Message)
{
}

UMaterialInstance* UFortKismetLibrary::SelectMaterialInstance(UMaterialInstance* A, UMaterialInstance* B, bool bSelectA)
{
	return nullptr;
}

void UFortKismetLibrary::SetActorEnableCollision_WithChildren(AActor* Target, const bool bEnable)
{
}

void UFortKismetLibrary::SetCameraComponentAdditiveOffset(UCameraComponent* CameraComponent, const FTransform& AdditiveTransformOffset, const float AdditiveFOVOffset)
{
}

void UFortKismetLibrary::SetCanBeDamaged(AActor* Actor, bool bCanBeDamaged)
{
}

void UFortKismetLibrary::SetComponentAffectNavigationGeneration(UActorComponent* Component, bool bAffectNavigation)
{
}

void UFortKismetLibrary::SetExtendedSafeZoneInfo(const AActor* ControllerOrPawn, bool bEnable)
{
}

void UFortKismetLibrary::SetGlobalTimeOfDayManager(UObject* WorldContextObject, TSoftClassPtr<AInfo> InTimeOfDayManager)
{
}

void UFortKismetLibrary::SetNiagaraAssetMatchActivation(UNiagaraComponent* NiagaraComponent, UNiagaraSystem* NiagaraSystem, bool bResetExistingOverrideParameters)
{
}

void UFortKismetLibrary::SetOutlinePostProcessEnabled(UObject* WorldContextObject, const bool bEnablePostProcess)
{
}

void UFortKismetLibrary::SetProjectileMovementDrunkData(AFortProjectileBase* Projectile, const FProjectileMovementDrunkConfig& NewConfig)
{
}

void UFortKismetLibrary::SetSceneCaptureShowFlags(USceneCaptureComponent2D* SceneCaptureComponent, const TArray<FEngineShowFlagsSetting>& ShowFlagSettings)
{
}

void UFortKismetLibrary::SetTimeOfDay(UObject* WorldContextObject, float TimeOfDay)
{
}

void UFortKismetLibrary::SetTimeOfDaySpeed(UObject* WorldContextObject, float TimeOfDaySpeedFactor)
{
}

bool UFortKismetLibrary::ShouldBlockQuestProgressReport(const UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::ShouldDisableMatchStatsDisplay(UObject* WorldContextObject)
{
	return false;
}

bool UFortKismetLibrary::ShouldHideTutorialWidget(FName WidgetName)
{
	return false;
}

void UFortKismetLibrary::ShowSoundIndicatorLocal(UObject* WorldContextObject, AActor* TrackedActor, FVector Location, float MaxAudibleDistance, EFortSoundIndicatorTypes IndicatorType, const TArray<AFortPlayerController*>& IgnoreOnControllers, const AActor* Instigator, FLinearColor Tint, UTexture* OverrideIcon, USoundBase* SoundBase)
{
}

void UFortKismetLibrary::ShowSoundIndicatorLocalForTeam(UObject* WorldContextObject, AActor* TrackedActor, FVector Location, float MaxAudibleDistance, EFortSoundIndicatorTypes IndicatorType, const TArray<AFortPlayerController*>& IgnoreOnControllers, uint8 Team, TArray<TEnumAsByte<EFortTeamAffiliation::Type>> Affiliations, const AActor* Instigator, FLinearColor Tint, UTexture* OverrideIcon, const USoundBase* SoundBase)
{
}

FVector UFortKismetLibrary::SnapToFortBuildingGrid(const FVector& InVector, const FVector PreSnapOffset, const FVector PostSnapOffset)
{
	return FVector();
}

AFortAreaOfEffectCloud* UFortKismetLibrary::SpawnAreaOfEffectCloud(TSubclassOf<AFortAreaOfEffectCloud> AreaOfEffectClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode)
{
	return nullptr;
}

ABuildingGameplayActor* UFortKismetLibrary::SpawnBuildingGameplayActor(TSubclassOf<ABuildingGameplayActor> BGAClass, const FTransform& Transform, AActor* Instigator, const bool bAutomaticallyInitialize, const bool bTransient)
{
	return nullptr;
}

ABuildingGameplayActor* UFortKismetLibrary::SpawnBuildingGameplayActorFromWorldContext(UObject* WorldContextObject, TSubclassOf<ABuildingGameplayActor> BGAClass, const FTransform& Transform, AActor* OptionalOwner, APawn* OptionalInstigator, const bool bTransient)
{
	return nullptr;
}

bool UFortKismetLibrary::SpawnInstancedPickupInWorld(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup)
{
	return false;
}

AFortPickup* UFortKismetLibrary::SpawnItemVariantPickupInWorld(UObject* WorldContextObject, FSpawnItemVariantParams Params)
{
	return nullptr;
}

AFortProjectileBase* UFortKismetLibrary::SpawnProjectile(TSubclassOf<AFortProjectileBase> ProjectileClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator SpawnRotation, const FRotator& SpawnDirection, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode, bool bUseDefaultPhysics, AActor* HomingTarget, float InitialSpeed, float GravityScale, float ChargePercent, const UFortWorldItemDefinition* OptionalAssociatedItemDef)
{
	return nullptr;
}

AFortProjectileBase* UFortKismetLibrary::SpawnProjectileWithParams(TSubclassOf<AFortProjectileBase> ProjectileClass, AActor* RequestedBy, FSpawnProjectileParams SpawnProjectileParams)
{
	return nullptr;
}

AFortTracerBase* UFortKismetLibrary::SpawnTracerFromPool(UObject* WorldContextObject, TSubclassOf<AFortTracerBase> TracerClass, const FVector& Origin, const FVector& Destination, AFortPawn* Instigator)
{
	return nullptr;
}

void UFortKismetLibrary::SpawnTransientActor(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, AActor*& SpawnedActor, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, AActor* OwnerActor, APawn* InstigatorPawn)
{
}

void UFortKismetLibrary::SpawnTransientSceneComponent(TSubclassOf<USceneComponent> ComponentClass, USceneComponent*& SpawnedComponent, AActor* OwnerActor, USceneComponent* InAttachParent, bool bRegister)
{
}

FString UFortKismetLibrary::ToLowerExceptIslandCode(const FString& InString)
{
	return FString();
}

void UFortKismetLibrary::TossPickupFromContainer(UObject* WorldContextObject, AActor* Container, AFortPickup* Pickup, const int32 NumSteps, const int32 Step, const float LootTossConeHalfAngle, const FRotator& LootTossDirection, const float LootTossSpeed, const bool bForceHidePickupMinimapIndicator)
{
}

FString UFortKismetLibrary::ToUpperExceptIslandCode(const FString& InString)
{
	return FString();
}

void UFortKismetLibrary::TriggerFeedbackEvent(UObject* WorldContextObject, FFortFeedbackHandle EventHandle, AFortPawn* InstigatorPawn, AFortPawn* Recipient, float OverriddenDelay, bool bOverriddenQueuing, bool bAllowReplication)
{
}

bool UFortKismetLibrary::TrySmartConsumeResources(int32 ResourceCost, AFortPlayerController* SourcePlayer)
{
	return false;
}

void UFortKismetLibrary::UnequipFortAbilitySet(FFortAbilitySetHandle& AbilitySetHandle)
{
}

void UFortKismetLibrary::UnhideAllTutorialWidgets(UObject* WorldContextObject)
{
}

void UFortKismetLibrary::UnhideTutorialWidget(UObject* WorldContextObject, FName WidgetName)
{
}

void UFortKismetLibrary::UnregisterGridFoundation(ABuildingFoundation* BuildingFoundation)
{
}

void UFortKismetLibrary::UpdatePlayerCustomCharacterPartsVisualization(AFortPlayerState* PlayerState)
{
}

bool UFortKismetLibrary::UpgradeAllWeaponsVerticalToRarity(AFortPlayerController* PlayerController, EFortRarity NewRarity, bool bThrottle)
{
	return false;
}

bool UFortKismetLibrary::ValidateOwnershipForGroupEmote(AFortPawn* Pawn, const UFortItemDefinition* EmoteDef)
{
	return false;
}

FVector UFortKismetLibrary::VectorSlerp(const FVector& Origin, const FVector& Start, const FVector& End, const float Alpha)
{
	return FVector();
}

float UFortKismetLibrary::VectorToNormalizedAngleInDegrees(FVector V)
{
	return float();
}
