// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityRepAnimMontage.h"
#include "AttributeSet.h"
#include "Components/TimelineComponent.h"
#include "Engine/CurveTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/SpringInterpolator.h"
#include "Engine/TimerHandle.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Abilities/FortCharacterPartMontageInfo.h"
#include "Abilities/ReplicatedMontagePair.h"
#include "Animation/FortAnimTypes.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "Building/BuildingTypes.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Capture/FortCarriedObjectHolderInterface.h"
#include "CosmeticModifierOwnerInterface.h"
#include "Cosmetics/FortCosmeticAssetContext.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Utility/ForniteLegacyCharacterCustomizationShims.h"
#include "Cosmetics/Variants/FortAppliedSwapItemAndVariantStateEnum.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "CosmeticsEventRegistrar.h"
#include "CosmeticsFinishable.h"
#include "CosmeticsMeshTarget.h"
#include "CosmeticsStreaming.h"
#include "Customization/AdaptiveCosmeticStats.h"
#include "Customization/BoneSetVisibilityInterface.h"
#include "Customization/CustomCharacterPartOwnerInterface.h"
#include "Customization/CustomColorSwatchType.h"
#include "Customization/CustomPlayerDataSource.h"
#include "Customization/FortBodyTypeProvider.h"
#include "Customization/FortGenderProvider.h"
#include "DelegateHandleController.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortCustomCharmTypeEnum.h"
#include "FortCustomPartTypeEnum.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortGender.h"
#include "FortInteractInterface.h"
#include "FortOnUIGameplayCueEvent.h"
#include "FortPawnDisplayContextEnum.h"
#include "FortVehicleTypes.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "Pawns/FortPawn.h"
#include "QueueWorkOptimalForPostTickInterface.h"
#include "FortPlayerPawn.generated.h"

class AActor;
class ABuildingGameplayActor;
class ABuildingGameplayActorPlayerPropAttachment;
class AController;
class ACustomCharacterPartModifier;
class AFortAIPawn;
class AFortAthenaVehicle;
class AFortAthenaZipline;
class AFortAthenaZiplineBase;
class AFortPickup;
class AFortPlayerCharm;
class AFortPlayerController;
class AFortPlayerControllerGameplay;
class AFortPlayerParachute;
class AFortPlayerPawn;
class AFortPlayerPet;
class AFortPlayerPetRepState;
class AFortRemoteControlledPawnAthena;
class AFortWaterBodyActor;
class AFortWeapon;
class APawn;
class APhysicsVolume;
class IFortArmoredInterface;
class IFortVehicleInterface;
class UActorComponent;
class UAnimInstance;
class UAnimMontage;
class UAssembledMeshSchema;
class UAthenaBackpackItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaCharmItemDefinition;
class UAthenaCosmeticItemDefinition;
class UAthenaGliderItemDefinition;
class UAthenaPetItemDefinition;
class UAthenaPickaxeItemDefinition;
class UAthenaSkyDiveContrailItemDefinition;
class UAudioComponent;
class UBoxComponent;
class UBuildingEditModeMetadata;
class UCharacterMovementComponent;
class UCosmeticDataComponent;
class UCosmeticsEarlyQRPComponent;
class UCurveFloat;
class UCustomCharacterPart;
class UCustomColorComponent;
class UCustomColorSwatch;
class UCustomPlayerComponent;
class UFXSystemAsset;
class UFXSystemComponent;
class UFortAIPawnCustomizationDefinition;
class UFortAbilitySystemComponent;
class UFortActorComponent_Affiliation;
class UFortAnimNotifyState_RootMotionInterrupt;
class UFortControllerComponent_TransientQuests;
class UFortCosmeticLoadoutComponent;
class UFortCustomizationAssetLoader;
class UFortFootstepAudioBank;
class UFortGameplayAbility;
class UFortGliderSpawnComponent;
class UFortHero;
class UFortHeroType;
class UFortLinkedAnimGraphComponent;
class UFortLocomotionAnimAsset;
class UFortMontageItemDefinitionBase;
class UFortPawnComponent_Convert;
class UFortPawnComponent_Tether;
class UFortPawnScriptedBehavior;
class UFortPawnSkeletalMeshContext;
class UFortPlayerAnimationComponent;
class UFortPlayerAnimationInterface;
class UFortUnderwaterDamageComponent;
class UFortVisibilityComponent;
class UFortWeaponAnimSet;
class UFortWorldItemDefinition;
class UGameplayAbility;
class UGameplayEffect;
class UInputComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraSystem;
class UObject;
class UParticleSystem;
class UParticleSystemComponent;
class UPostProcessComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USkeletalMeshComponentBudgeted;
class USoundBase;
class UTexture;
class UWidget;
enum class EFortAppliedSwapItemAndVariantState : uint8;
enum class EFortDBNOCarryEvent : uint8;
enum class EFortFacialAnimTypes : uint8;
enum class EFortPawnDisplayContext : uint8;
enum class EFortPawnStasisMode : uint8;
enum class EItemInteractionStatus : uint8;
enum class EItemInteractionType : uint8;
enum class ETryExitVehicleBehavior : uint8;

UENUM(BlueprintType)
enum class EBodyPartVisibilityGrouping : uint8
{
	AllParts = 0,
	AllButHead = 1,
	OnlyBackBling = 2,
	BackBlingAndCharm = 3,
	OnlyBody = 4,
	OnlyHead = 5,
	OnlyTail = 6,
};

UENUM(BlueprintType)
enum class EFortDBNOCarryEvent : uint8
{
	PickedUp = 0,
	Interrogating = 1,
	Dropped = 2,
	Thrown = 3,
};

UENUM()
enum class EFortPartVisibility : uint8
{
	Visible = 0,
	Hidden = 1,
	HiddenCastShadow = 2,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EFortPawnMaterialOverrideFlags : uint8
{
	None = 0,
	/** Hides particle systems when override is active */
	HideParticleSystems = 1,
	/** Apply material override to the pawn's held weapon */
	ApplyToWeapon = 2,
	/** Apply material override to any emote props */
	ApplyToEmoteProps = 4,
	/**
	 * Respect the state of a character part's IgnoredMaterialOverrideIndices - allows parts to not apply uniform 
	 * material overrides to specific material indices (e.g. for body bag meshes on toon characters)
	 */
	RespectPartOverrides = 8,
};

UENUM()
enum class EFortPawnStasisMode : uint8
{
	/** No restrictions on pawn movement nor actions. */
	None = 0,
	/** The pawn canNOT do native actions nor move. They can still turn and fall. */
	NoMovement = 1,
	/** The pawn canNOT do native actions, move nor turn. They can still fall. */
	NoMovementOrTurning = 2,
	/** The pawn canNOT do native actions, move, turn, nor fall */
	NoMovementOrFalling = 3,
	/** The pawn canNOT do most native actions nor move. They can still turn, fall, and perform emotes. */
	NoMovement_EmotesEnabled = 4,
	/** The pawn canNOT do most native actions, move nor turn. They can still fall and perform emotes. */
	NoMovementOrTurning_EmotesEnabled = 5,
	/** The pawn canNOT do most native actions, move, turn, nor fall. They can still perform emotes. */
	NoMovementOrFalling_EmotesEnabled = 6,
};

UENUM(BlueprintType)
enum class EItemInteractionStatus : uint8
{
	Interrupted = 0,
	Completed = 1,
	TimedOut = 2,
};

UENUM(BlueprintType)
enum class EItemInteractionType : uint8
{
	Search = 0,
	LockOnSearch = 1,
	None = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAbilitySystemInitializedDelegate, UFortAbilitySystemComponent*, AbilitySystemComponent, AFortPlayerPawn*, AffectedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterPartChanged, TEnumAsByte<EFortCustomPartType::Type>, PartType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterPartVisibilityChanged, TEnumAsByte<EFortCustomPartType::Type>, PartType, bool, bVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortPlayerPawnDelegate, AFortPlayerPawn*, PlayerPawn);

USTRUCT(BlueprintType)
struct FFortPawnMaterialOverrideCopiedParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnMaterialOverrideCopiedParameters")
	TArray<FName> ScalarParamNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnMaterialOverrideCopiedParameters")
	TArray<FName> VectorParamNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnMaterialOverrideCopiedParameters")
	TArray<FName> TextureParamNames;

};

USTRUCT(BlueprintType)
struct FFortPawnMaterialOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPawnMaterialOverride")
	FGuid OverrideId;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnMaterialOverride")
	TSoftObjectPtr<UMaterialInterface> Material;

	UPROPERTY()
	FFortPawnMaterialOverrideCopiedParameters MaterialParamsToCopy;

	UPROPERTY()
	float Priority;

	UPROPERTY()
	EFortPawnMaterialOverrideFlags Flags;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMaterialOverrideAppliedDelegate, AFortPlayerPawn*, AffectedPawn, const FFortPawnMaterialOverride&, AppliedOverride);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaterialOverrideClearedDelegate, AFortPlayerPawn*, AffectedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewPlayerStateDelegate, AFortPlayerPawn*, AffectedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActivateAbility, UFortGameplayAbility*, GameplayAbility, FGameplayTagContainer, AbilityTags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBallooningGravityCeilingChanged, int32, RelationToCeiling);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBeginParachuteMovementEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBeginSkydivingEvent);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnCosmeticMeshAppliedBPWithAnyStruct, AFortPlayerPawn*, Pawn, USkeletalMeshComponent*, BaseMesh, const FInstancedStruct&, AnyStruct);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnCosmeticMeshAppliedBP, AFortPlayerPawn*, Pawn, USkeletalMeshComponent*, BaseMesh);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FiveParams(FOnCosmeticPartAppliedBPWithAnyStruct, AFortPlayerPawn*, Pawn, UCustomCharacterPart*, Part, USkeletalMeshComponent*, MeshPart, const TEnumAsByte<EFortCustomPartType::Type>, PartType, const FInstancedStruct&, AnyStruct);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnCosmeticPartAppliedBP, AFortPlayerPawn*, Pawn, UCustomCharacterPart*, Part, USkeletalMeshComponent*, MeshPart, const TEnumAsByte<EFortCustomPartType::Type>, PartType);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FiveParams(FOnCosmeticsAppliedBPWithAnyStruct, AFortPlayerPawn*, Pawn, USkeletalMeshComponent*, BaseMesh, const TArray<UCustomCharacterPart*>&, PartsArray, const TArray<USkeletalMeshComponent*>&, ValidSkeletalMeshComponentPartArray, const FInstancedStruct&, AnyStruct);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnCosmeticsAppliedBP, AFortPlayerPawn*, Pawn, USkeletalMeshComponent*, BaseMesh, const TArray<UCustomCharacterPart*>&, PartsArray, const TArray<USkeletalMeshComponent*>&, ValidSkeletalMeshComponentPartArray);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrouchInputJustPressed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDBNOHoisterChanged, EFortDBNOCarryEvent, CarryEvent, AFortPlayerPawn*, HoisterPawn, AFortPlayerPawn*, HoisteePawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDamageComboIncrement, int32, Count, int32, DamageTaken);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamageComboReset);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmoteInteracted, AFortPlayerPawn*, Instigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndParachuteMovementEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndSkydivingEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndedInteractSearch);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnteredAircraft);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFinishedCharacterCustomization, AFortPlayerPawn*, Pawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFiringRangedWeapon, UFortGameplayAbility*, GameplayAbility, FGameplayTagContainer, AbilityTags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFootstepEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGroupEmoteFollowerJoined, AFortPlayerPawn*, JoiningPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGroupEmoteFollowerLeft, AFortPlayerPawn*, LeavingPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGroupEmoteSecondaryFirePressed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGroupEmoteSyncValueChanged, uint8, NewSyncValue);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeldObjectChanged, AActor*, HeldObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInstantInteractSearch);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJumpInput, bool, bPressed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, Val);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveRight, float, Val);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnEnterWater, AFortPlayerPawn*, FortPlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnExitSwinging);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnExitWater, AFortPlayerPawn*, FortPlayerPawn, const bool, bPawnIsOutsideOfAllWaterBodies);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPetAddedOrRemoved, const AFortPlayerPawn*, FortPlayerPawn, const UAthenaPetItemDefinition*, PetItemDef);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnPosessionChanged, APawn*, Pawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerRevivedFromDBNO, AFortPlayerPawn*, RevivedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPossessedProp, AFortPlayerPawn*, FortPlayerPawn, ABuildingGameplayActorPlayerPropAttachment*, PossessedProp);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPreDetachAbilitySystemComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPreInvalidateAbilitySystemComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRevivePlayerFromDBNO, AFortPlayerPawn*, RevivedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSafeZoneOccupancyChanged, AFortPlayerPawn*, PlayerPawn, bool, bIsInSafeZone);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartedInteractSearch);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStopSliding, AFortPlayerPawn*, FortPlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleSpawned, AFortAthenaVehicle*, Vehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVehicleStateChangeEvent, AFortPlayerPawn*, FortPlayerPawn, AActor*, NewVehicle, AActor*, OldVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FParachuteSpawnedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FZiplinePostBegin);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FZiplineStateChanged, bool, bIsZiplining, AFortPlayerPawn*, FortPlayerPawn);

USTRUCT()
struct FAnimSetOverrideData
{
	GENERATED_BODY()

};

USTRUCT()
struct FDBNOData
{
	GENERATED_BODY()

};

USTRUCT()
struct FDownerInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortCharacterPartsRepMontageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortCharacterPartMontageInfo> CharPartMontages;

	UPROPERTY()
	TObjectPtr<UAnimMontage> PawnMontage;

	UPROPERTY()
	bool bPlayBit;

};

USTRUCT()
struct FFortDBNOCarryHoisterData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> DBNOHoister;

	UPROPERTY()
	EFortDBNOCarryEvent DBNOCarryEvent;

};

USTRUCT()
struct FFortFootstepBankOverrideData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortPawnMaterialOverrideState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPawnMaterialOverrideState", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SceneComp;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnMaterialOverrideState")
	TArray<TObjectPtr<UMaterialInterface>> OriginalMaterials;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnMaterialOverrideState")
	TArray<TObjectPtr<UMaterialInterface>> AppliedMaterials;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPawnMaterialOverrideState", meta=(EditInline="true"))
	TArray<TObjectPtr<UFXSystemComponent>> FXComps;

};

USTRUCT()
struct FFortPawnMaterialScalarOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ParamName;

	UPROPERTY()
	float Value;

	UPROPERTY()
	uint8 bOverrideActive : 1;

};

USTRUCT()
struct FFortPickupRequestInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid SwapWithItem;

	UPROPERTY()
	float FlyTime;

	UPROPERTY()
	FVector Direction;

	UPROPERTY()
	uint8 bPlayPickupSound : 1;

	UPROPERTY()
	uint8 bIsAutoPickup : 1;

	UPROPERTY()
	uint8 bUseRequestedSwap : 1;

	UPROPERTY()
	uint8 bTrySwapWithWeapon : 1;

	UPROPERTY()
	uint8 bIsVisualOnlyPickup : 1;

};

USTRUCT()
struct FFortPlayerPawnObjectReference
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> TrackedObject;

};

USTRUCT()
struct FFortRedeployGliderTelemetryData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortTetherSessionTelemetryInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FIgnoreCollisionActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> IgnoreActor;

	UPROPERTY(Transient)
	float TimeIgnoreStarted;

	UPROPERTY(Transient)
	float IgnoreDuration;

};

USTRUCT()
struct FPlayerPawnShallowWaterVolumeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsInWaterVolume;

	UPROPERTY()
	FGameplayTag ActionTag;

};

USTRUCT()
struct FPreviouslyAppliedVariantData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UAthenaCharacterItemDefinition> Character;

	UPROPERTY()
	TObjectPtr<UAthenaSkyDiveContrailItemDefinition> Contrail;

	UPROPERTY()
	TObjectPtr<UAthenaPickaxeItemDefinition> Pickaxe;

	UPROPERTY()
	TObjectPtr<UAthenaBackpackItemDefinition> Backpack;

	UPROPERTY()
	TArray<FMcpVariantChannelInfo> Variants;

};

USTRUCT()
struct FRepFortMeshAttachment
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY()
	TSubclassOf<UAnimInstance> AnimBP;

};

USTRUCT(BlueprintType)
struct FSlipperySlopeParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeForceAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat MaxLateralSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat MaxLateralSpeedMultiplierInWater;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat BrakingDecelerationInWater;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat BrakingDecelerationFactorOnSlope;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat MaxInhibitingSlopeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat MaxInhibitingSlopeSpeedFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat MaxVerticalLaunchSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLandingForceScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLandingMaxHorizontalForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLaunchMinRequiredSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLaunchMinRequiredAngleChange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLaunchVerticalVelocityBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperySlopeParams")
	FScalableFloat SlopeLaunchVerticalVelocityBoostMultiplierJumping;

};

USTRUCT()
struct FZiplinePawnState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortAthenaZiplineBase> Zipline;

	UPROPERTY(NotReplicated)
	TWeakObjectPtr<AFortAthenaZiplineBase> PreviousZipline;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> InteractComponent;

	UPROPERTY()
	bool bIsZiplining;

	UPROPERTY()
	bool bJumped;

	UPROPERTY()
	bool bReachedEnd;

	UPROPERTY()
	int32 AuthoritativeValue;

	UPROPERTY()
	FVector SocketOffset;

	UPROPERTY(NotReplicated)
	float TimeZipliningBegan;

	UPROPERTY(NotReplicated)
	float TimeZipliningEndedFromJump;

	UPROPERTY(NotReplicated)
	FTimerHandle RemoveZiplineFromIgnoreWhenMovingTimerHandle;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortPlayerPawn : public AFortPawn, public IFortCarriedObjectHolderInterface, public IFortInteractInterface, public ICustomCharacterPartOwnerInterface, public IBoneSetVisibilityInterface, public IFortUICameraFrameTargetInterface, public ICustomPlayerDataSource, public IFortCosmeticAssetContext, public IFortDataRegistryResolverScopeInterface, public ICosmeticsMeshTarget, public ICosmeticsFinishable, public ICosmeticsStreaming, public ICosmeticModifierOwnerInterface, public IFortBodyTypeProvider, public IFortGenderProvider, public IFortniteCharacterCustomizerLegacy, public IQueueWorkOptimalForPostTickInterface, public ICosmeticsEventRegistrar
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Character")
	void AddAttachment(USkeletalMesh* Attachment, TSubclassOf<UAnimInstance> InAnimBP);

	UFUNCTION(BlueprintCallable, Category="Collision")
	void AddIgnoredActor(AActor* InActorToIgnore, const float InIgnoreDuration);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Stasis", meta=(AutoCreateRefTerm="InStasisGameplayTag, AllowedActionTags", CPP_Default_BoundStasisInstigator="None", CPP_Default_InStasisGameplayTag="()", CPP_Default_AllowedActionTags="()"))
	void AddStasisMode(const EFortPawnStasisMode InStasisMode, AActor* BoundStasisInstigator, const FGameplayTag& InStasisGameplayTag, const FGameplayTagContainer& AllowedActionTags);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void AllowPickupInteractionWhileSkydiving(const bool bAllow);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Animation")
	void AnimTrailsDisable();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Animation")
	void AnimTrailsNotify(bool bActive);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Animation")
	void AnimTrailsSetup(UParticleSystem* ParticleSystemReference, UNiagaraSystem* NiagaraSystemReference, FName FirstSocketName, FName SecondSocketName, float Width, UFXSystemComponent* OverrideParticleComp, FName OverideFirstSocketName, FName OverideSecondSocketName);

	UFUNCTION(BlueprintCallable, Category="Variants")
	void ApplyCosmeticLoadout();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="MaterialParamsToCopy", DeprecatedFunction, DeprecationMessage="Please use ApplyMaterialOverrideWithFlags instead"))
	FGuid ApplyMaterialOverride(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority = 0.000000f, bool bHideParticleSystems = false, bool bApplyToWeapon = false);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="MaterialParamsToCopy", DeprecatedFunction, DeprecationMessage="Please use ApplyMaterialOverrideLocaWithFlags instead"))
	FGuid ApplyMaterialOverrideLocal(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority = 0.000000f, bool bHideParticleSystems = false, bool bApplyToWeapon = false);

	UFUNCTION(BlueprintCallable, Category="SaveTheWorld")
	void ApplyWrapToSaveTheWorldHoverboard();

	UFUNCTION(BlueprintPure)
	bool AreFXHidden() const;

	UFUNCTION(BlueprintPure)
	bool AreFXHiddenForPartComponent(const USkeletalMeshComponent* PartMeshComponent) const;

	UFUNCTION(BlueprintCallable, Category="Interact")
	void AttemptInstantInteractSearch();

	UFUNCTION(Server, Reliable)
	void AuthUpdateLockedFloatSliderVariant(const UAthenaCosmeticItemDefinition* ItemVariantIsUsedFor, const FGameplayTag& ChannelTag);

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void BeginHovering();

	UFUNCTION(BlueprintCallable, Category="Parachute")
	void BeginSkydiving(bool bFromBus);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Zipline")
	void BeginZiplining(AFortAthenaZipline* Zipline, USceneComponent* SocketComponent, UPrimitiveComponent* InteractComponent);

	UFUNCTION(Exec)
	void BlindTestPredictiveInput();

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="MaterialParamsToCopy", DisplayName="Apply Material Override Local with Flags"))
	FGuid BP_ApplyMaterialOverrideLocalWithFlags(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority = 0.000000f, int32 Flags = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="MaterialParamsToCopy", DisplayName="Apply Material Override with Flags"))
	FGuid BP_ApplyMaterialOverrideWithFlags(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority = 0.000000f, int32 Flags = 0);

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DisplayName="Get Vehicle"))
	AFortAthenaVehicle* BP_GetVehicle() const;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Animation")
	void BroadcastClearWeaponOverrideAnimSet();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Animation")
	void BroadcastSetWeaponOverrideAnimSet(UFortWeaponAnimSet* WeaponOverrideAnimSet);

	UFUNCTION(BlueprintCallable)
	bool BufferCrouchCommand();

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void CancelJumpAbility();

	UFUNCTION(BlueprintCallable)
	virtual bool CanInterrogateFromDBNO(AController* EventInstigator);

	UFUNCTION(BlueprintCallable, Category="PlayerPawnStats")
	bool CanPredictJumpApex();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool CanShootFromVehicle() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool CanUseInventoryAsDriver() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void CheckForUnburrowTeleport();

	UFUNCTION(BlueprintCallable, Category="Customization")
	void ClearExistingCosmeticPetInstance();

	UFUNCTION(BlueprintCallable)
	void ClearScalarMaterialParameterOverrideLocal(FName ParamName);

	UFUNCTION(BlueprintCallable, Category="AnimSets")
	void ClearWeaponOverrideAnimSet();

	UFUNCTION(Client, Unreliable)
	void ClientAcknowledgeVehicleInputState(float Timestamp);

	UFUNCTION(Client, Reliable)
	void ClientExecuteGameplayCueOnSpecificPlayer(const FGameplayTag GameplayCueTag);

	UFUNCTION(Client, Unreliable)
	void ClientNotifyAbilityFailed(const UGameplayAbility* FailedAbility, const FGameplayTagContainer& FailedReason);

	UFUNCTION(Client, Unreliable)
	void ClientNotifyUnableToPerformAction(bool bPlayMontage, const FGameplayTagContainer& FailedReason);

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void ClientResetAbilitySystemComponent();

	UFUNCTION(BlueprintCallable)
	void ConstructItemSwapClonedFromLoadout(const FFortAthenaLoadout& Loadout, const UAthenaCosmeticItemDefinition* Item, FFortSwapItemAndVariantData& SwapData);

	UFUNCTION(Exec)
	void DebugDestroyVehicle();

	UFUNCTION(BlueprintCallable, Category="Balloon")
	void DestroyBalloonRope();

	UFUNCTION(BlueprintCallable)
	void DisableCosmeticSwap(const FGuid& SwapId);

	UFUNCTION(BlueprintCallable, Category="Stasis")
	void DisableFaceRotation(float DurationInSeconds, bool bSetStasis = false);

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual bool DontCrossArms() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual bool DontHandsOnHips() const;

	UFUNCTION()
	void DriverToPassengerAnimationStopped();

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void EndFloating();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GhostMode")
	void EndGhostModeExit();

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void EndHovering();

	UFUNCTION(BlueprintCallable, Category="Parachute")
	virtual void EndSkydiving();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Zipline")
	void EndZiplining(bool bFromJump = false, bool bReachedEnd = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="RemoteControlPawn")
	void ForceDetachFromRemoteControlledPawn();

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FGameplayTagContainer GatherMetaTags(const UAthenaCosmeticItemDefinition* CosmeticItem) const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerFootSplashInWaterLeftComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerFootSplashInWaterRightComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerHandSplashInWaterComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerInWaterComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerJumpSplashInWaterComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerSwimmingComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetActivePlayerWaterBoostComponent() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Zipline")
	AFortAthenaZiplineBase* GetActiveZipline() const;

	UFUNCTION(BlueprintPure, Category="Animation")
	UFortPlayerAnimationInterface* GetAnimationInterface() const;

	UFUNCTION(BlueprintPure, Category="FortPlayerPawn")
	float GetBaseAimPitchQuantized() const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	float GetBuildCostModifier() const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	float GetBuildSpeedModifier() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="AthenaPawn")
	int32 GetCachedFootstepIndex() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="AthenaPawn")
	FVector GetCachedStepSurfaceNormal() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	EFortCustomBodyType::Type GetCharacterBodyType() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual AFortPlayerCharm* GetCharacterCharmActorForCharmType(EFortCustomCharmType::Type CharmType) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	EFortCustomGender::Type GetCharacterGender() const;

	UFUNCTION(BlueprintPure)
	int32 GetClientObservedStatValue(const FName& StatName, int32 DefaultValue) const;

	UFUNCTION(BlueprintPure, Category="Customization", meta=(ComponentClass="/Script/Engine.ActorComponent", DeterminesOutputType="ComponentClass"))
	TArray<UActorComponent*> GetComponentsByClassForPartType(TSubclassOf<UActorComponent> ComponentClass, EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="Customization", meta=(ComponentClass="/Script/Engine.ActorComponent", DeterminesOutputType="ComponentClass"))
	TArray<UActorComponent*> GetComponentsByClassOnAllPartModifiers(TSubclassOf<UActorComponent> ComponentClass) const;

	UFUNCTION(BlueprintCallable, Category="Parachute")
	virtual TSoftObjectPtr<UFXSystemAsset> GetContrailParticleSystemSoftRef();

	UFUNCTION(BlueprintPure)
	virtual AFortPlayerPawn* GetControllingPawn() const;

	UFUNCTION(BlueprintPure, Category="Cosmetic")
	UCosmeticDataComponent* GetCosmeticDataComponent() const;

	UFUNCTION(BlueprintPure, Category="Cosmetic")
	UFortCosmeticLoadoutComponent* GetCosmeticLoadoutComponent() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetDBNOHoistee() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetDBNOHoister() const;

	UFUNCTION(BlueprintPure, Category="Hero")
	EFortPawnDisplayContext GetDisplayContext() const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	int32 GetExtraLives() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual UAnimMontage* GetFrontendAnimMontageIdleOverride() const;

	UFUNCTION(BlueprintPure, Category="FortPlayerPawn")
	void GetGender(bool& IsMale, bool& IsFemale) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	FText GetGliderDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Spawn")
	AActor* GetHomeActor() const;

	UFUNCTION(BlueprintPure)
	bool GetIsHoldingObject() const;

	UFUNCTION(BlueprintPure, Category="FX")
	void GetLastWaterSurfaceInfo(FVector& OutWaterSurfacePosition, FVector& OutWaterSurfaceNormal);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	virtual AFortWeapon* GetLastWeaponEquippedOnServer() const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	float GetMaxStamina() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="FortPawn")
	ACustomCharacterPartModifier* GetModifierForPartType(EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="Balloon")
	int32 GetNumActiveBalloons() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	const FFortAthenaLoadout& GetPawnCosmeticLoadout(const bool bGetBaseLoadout = false, const bool bWarn = true) const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool GetPendingSkydiveLaunch() const;

	UFUNCTION(BlueprintPure, Category="PropHunt")
	ABuildingGameplayActorPlayerPropAttachment* GetPossessedProp() const;

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	const FVector GetPreviousPosition();

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	const FVector GetPreviousVelocity();

	UFUNCTION(BlueprintPure)
	FRotator GetRemoteViewRotation() const;

	UFUNCTION(BlueprintPure, Category="LOD")
	int32 GetSignificanceLOD() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="GadgetAttributeSets")
	float GetSimulatedAttributeValue(const FGameplayAttribute& Attribute, const float DefaultValue) const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual USkeletalMeshComponent* GetSkeletalMeshForCharmType(EFortCustomCharmType::Type CharmType) const;

	UFUNCTION(BlueprintPure, Category="Customization", meta=(Namespace="Fortnite.Cosmetics"))
	USkeletalMeshComponent* GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	float GetStamina() const;

	UFUNCTION(BlueprintPure, Category="Stasis", meta=(DeprecatedFunction, DeprecationMessage="Players can now have multiple stasis modes. To determine if the player is affected by a specific stasis mode, IsInStasisMode should be used. Otherwise use GetStasisModes."))
	EFortPawnStasisMode GetStasisMode() const;

	UFUNCTION(BlueprintPure, Category="Stasis")
	const TArray<EFortPawnStasisMode>& GetStasisModes() const;

	UFUNCTION(BlueprintPure)
	APawn* GetTetherPawn() const;

	UFUNCTION(BlueprintPure)
	USkeletalMesh* GetTetherRopeRodMesh() const;

	UFUNCTION(BlueprintPure)
	FHitResult GetThrownItemTrajectoryHitResult() const;

	UFUNCTION(BlueprintPure)
	UFortControllerComponent_TransientQuests* GetTransientQuestsComponent() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	AActor* GetVehicleActor() const;

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	bool GetVehicleOverrideExit();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	int32 GetVehicleSeatIndex() const;

	UFUNCTION(BlueprintPure, Category="Vehicle", meta=(DisplayName="GetVehicleInterface"))
	virtual TScriptInterface<IFortVehicleInterface> GetVehicleUInterface() const;

	UFUNCTION(BlueprintPure, Category="Zipline")
	float GetZiplineSpeedFactor() const;

	UFUNCTION(BlueprintPure, Category="Zipline")
	float GetZiplineSpeedFactorTarget() const;

	UFUNCTION(Exec)
	void HACK_ApplyCosmetics(const FString& ApplyCosmetics);

	UFUNCTION(BlueprintPure, Category="RemoteControlPawn")
	bool HasControlledRCPawn() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	bool HasPendingVariantAssets() const;

	UFUNCTION(BlueprintPure, Category="Zipline")
	bool HasRecentlyExitedZiplineFromJumping() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool HasRespawnedInAir() const;

	UFUNCTION(BlueprintPure, Category="Floating")
	bool HasStartedFloating() const;

	UFUNCTION(BlueprintCallable, Category="FX")
	void InvokeWaterHandSplash(const FVector& SplashPosition);

	UFUNCTION(BlueprintCallable, Category="FX")
	void InvokeWaterHandSplashAttached(USceneComponent* AttachParent, FName AttachSocketName);

	UFUNCTION(BlueprintCallable, Category="FX")
	void InvokeWaterJumpSplash(const FVector& SplashPosition, float SplashScale = 1.000000f);

	UFUNCTION(BlueprintPure, Category="Parachute")
	virtual bool IsActivelySkydiving(const bool bCheckMovementMode = true) const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsActivelySkydivingUpInVortex() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsActivelyStrafingInAir(const bool bCheckMovementMode = true) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	bool IsCharacterCustomizationLoadingCompleted() const;

	UFUNCTION(BlueprintPure)
	bool IsComponentCharacterPartMesh(const USkeletalMeshComponent* SkeletalMeshComponent) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	bool IsCoreCharacterCustomizationLoadingCompleted() const;

	UFUNCTION(BlueprintPure, Category="FortMovement")
	bool IsCrouchInputBuffered() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsDrivingInteractBlockingVehicle() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsDrivingVehicle() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsEmoteBlockedByMovement() const;

	UFUNCTION(BlueprintPure, Category="DBNO")
	virtual bool IsImprovedDBNOEnabled() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	bool IsInCharacterCustomization() const;

	UFUNCTION(BlueprintPure, Category="Floating")
	bool IsInFloatingMovement() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	bool IsInFrontEndHologram() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	virtual bool IsInInteractBlockingVehicle() const;

	UFUNCTION(BlueprintPure, Category="SlipperyMovement")
	bool IsInSlipperyMovement() const;

	UFUNCTION(BlueprintPure, Category="Stasis")
	bool IsInStasis() const;

	UFUNCTION(BlueprintPure, Category="Stasis")
	bool IsInStasisMode(const EFortPawnStasisMode InStasisMode) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsInVehicle() const;

	UFUNCTION(BlueprintPure)
	bool IsItemAndVariantSwapActiveById(const FGuid& SwapID) const;

	UFUNCTION(BlueprintCallable, meta=(ReturnDisplayName="IsApplied"))
	bool IsMaterialOverrideApplied(const FGuid& MaterialOverrideId, bool& bOutIsCurrentOverride);

	UFUNCTION(BlueprintPure)
	bool IsNiagaraProceduralWaterSim() const;

	UFUNCTION(BlueprintPure)
	bool IsNiagaraSimpleWaterSim() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsOperatingTurret() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsParachuteForcedOpen() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsParachuteOpen() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsParachuteOpenAndVisible() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Character Part")
	bool IsPartVisibleAccordingToCount(EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsPassengerInVehicle() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsPassivelySkydiving() const;

	UFUNCTION(BlueprintPure, Category="Interaction")
	bool IsPickupInteractionWhileSkydivingAllowed() const;

	UFUNCTION(BlueprintPure, Category="FortMovement")
	bool IsRidingOnActor() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsSkydiving() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsSkydivingFromBus() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsSkydivingFromLaunchPad() const;

	UFUNCTION(BlueprintPure, Category="PlayerPawnStats")
	bool IsSprinting() const;

	UFUNCTION(BlueprintPure)
	bool IsTethered() const;

	UFUNCTION(BlueprintPure, Category="Character")
	bool IsUsingPersonalVehicle() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	virtual bool IsUsingUmbrella() const;

	UFUNCTION(BlueprintPure, Category="Water")
	bool IsWaterSprintBoosting() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Zipline")
	bool IsZiplining() const;

	UFUNCTION(BlueprintCallable)
	virtual bool LocalIsTryingToGetPickup();

	UFUNCTION(BlueprintCallable)
	void LocalThrowCarriedPlayer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPlayerPawn")
	void ManualReviveFromDBNO(TSubclassOf<UGameplayEffect> ReviveGameplayEffectsOverride = nullptr);

	UFUNCTION(BlueprintCallable, Category="SafeZone")
	void MarkSafe(TSubclassOf<UGameplayEffect> GEtoApply);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Animation")
	void MulticastClearWeaponOverrideAnimSet();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Animation")
	void MulticastSetWeaponOverrideAnimSet(UFortWeaponAnimSet* WeaponOverrideAnimSet);

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void NotifyTeammateSkydivedFromBus();

	UFUNCTION(BlueprintNativeEvent)
	void OnBeginParachuteMovement();

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnBeginWaterSprintBoost();

	UFUNCTION(BlueprintNativeEvent)
	void OnEndParachuteMovement();

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnEndWaterSprintBoost();

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnEnteredVehicle();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnEnteredWaterVolume(const FVector& WaterSurfaceLocation);

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnExitedVehicle();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnExitedWaterVolume(const FVector& WaterSurfaceLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLandscapeCheckFailedAndTeleported();

	UFUNCTION(BlueprintImplementableEvent, Category="interact")
	void OnLocalItemInteractionComplete(AActor* ReceivingActor);

	UFUNCTION(BlueprintImplementableEvent, Category="interact")
	void OnLockOnSearchCompleted(bool& bConsumeEvent);

	UFUNCTION()
	void OnRep_AccelerationPack();

	UFUNCTION()
	void OnRep_AccelerationZPack();

	UFUNCTION()
	void OnRep_AnimBPOverride();

	UFUNCTION()
	void OnRep_AnimLayersOverride();

	UFUNCTION()
	void OnRep_CustomMeshHeightAdjustTarget();

	UFUNCTION()
	void OnRep_DBNOHoistee();

	UFUNCTION()
	void OnRep_DBNOHoisterData(const FFortDBNOCarryHoisterData& PreviousDBNOHoisterData);

	UFUNCTION()
	void OnRep_FootstepBankOverride();

	UFUNCTION()
	void OnRep_GroupEmoteSyncValue();

	UFUNCTION()
	void OnRep_IsInAnyStorm();

	UFUNCTION()
	void OnRep_IsInsideSafeZone();

	UFUNCTION()
	void OnRep_IsInWaterVolume();

	UFUNCTION()
	void OnRep_IsTacticalSprinting();

	UFUNCTION()
	void OnRep_StasisModes();

	UFUNCTION()
	void OnRep_UpdateContextTracker();

	UFUNCTION()
	void OnRep_VehicleInputStateReliableForReplay();

	UFUNCTION()
	void OnRep_ZiplineState(const FZiplinePawnState& PreviousValue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="AthenaPawn")
	void OnSignificanceLODChanged(int32 NewLOD);

	UFUNCTION(BlueprintImplementableEvent, Category="interact")
	void OnStartLongInteract(AActor* ReceivingActor, bool& Out_bConsumeEvent, bool& Out_bSkipSetInteractDuration, bool& Out_bSkipStartAnimation, EItemInteractionType& Out_ItemInteractionType);

	UFUNCTION(BlueprintCallable)
	void OnTacticalSprintEnded();

	UFUNCTION(BlueprintCallable)
	void OnTacticalSprintStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTetheredExitPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTetheredExitReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTetherEnded(APawn* LastTetherPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTetherStarted(APawn* LastTetherPawn);

	UFUNCTION()
	virtual void OnWeaponEquippedNative(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon);

	UFUNCTION(BlueprintCallable)
	void OverrideScalarMaterialParameterLocal(FName ParamName, float Value);

	UFUNCTION()
	void PassengerToDriverAnimationStopped();

	UFUNCTION()
	void PassengerToPassengerAnimationStopped();

	UFUNCTION()
	virtual void PerformSupplementalKillVolumeSweep();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PlayGroupEmote(const UFortMontageItemDefinitionBase* EmoteAsset);

	UFUNCTION()
	void PopAnimBPOverride(int32 Priority, TSubclassOf<UAnimInstance> InAnimBPOverride);

	UFUNCTION()
	void PopAnimLayersOverride(int32 Priority, const TArray<TSubclassOf<UAnimInstance>>& InAnimLayersOverride);

	UFUNCTION()
	void PopFootstepBankOverride(int32 Priority, UFortFootstepAudioBank* InFootstepBankOverride);

	UFUNCTION()
	void PopLocomotionAnimSetOverride(int32 Priority, UFortLocomotionAnimAsset* InLocomotionAnimAssetOverride);

	UFUNCTION()
	void PopWeaponAnimSetOverride(int32 Priority, UFortWeaponAnimSet* InWeaponAnimSetOverride);

	UFUNCTION(BlueprintCallable)
	void PostResIn();

	UFUNCTION()
	void PushAnimBPOverride(int32 Priority, TSubclassOf<UAnimInstance> InAnimBPOverride);

	UFUNCTION()
	void PushAnimLayersOverride(int32 Priority, const TArray<TSubclassOf<UAnimInstance>>& InAnimLayersOverride);

	UFUNCTION()
	void PushFootstepBankOverride(int32 Priority, UFortFootstepAudioBank* InFootstepBankOverride);

	UFUNCTION()
	void PushLocomotionAnimSetOverride(int32 Priority, UFortLocomotionAnimAsset* InLocomotionAnimAssetOverride);

	UFUNCTION()
	void PushWeaponAnimSetOverride(int32 Priority, UFortWeaponAnimSet* InWeaponAnimSetOverride);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Stasis")
	void RemoveAllDefaultStasisApplications();

	UFUNCTION(BlueprintCallable, Category="Character")
	void RemoveAttachment();

	UFUNCTION()
	void RemoveExpiredIgnoredActorsAndCheckForNextTimer();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool RemoveMaterialOverride(const FGuid& MaterialOverrideId);

	UFUNCTION(BlueprintCallable)
	bool RemoveMaterialOverrideLocal(const FGuid& MaterialOverrideId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Stasis", meta=(AutoCreateRefTerm="InStasisGameplayTag", CPP_Default_InStasisGameplayTag="()"))
	void RemoveStasisMode(const FGameplayTag& InStasisGameplayTag, const bool bRemoveAllOfThisTag = false);

	UFUNCTION(BlueprintCallable, Category="Animation")
	void ResetClothAndDynamics();

	UFUNCTION(BlueprintCallable, Category="Animation")
	void ResetClothAndDynamicsMatching(const FGameplayTagContainer& MatchingTags);

	UFUNCTION(BlueprintCallable)
	virtual void ResetGameplayAttributes(const bool bIgnoreStatClamp);

	UFUNCTION()
	void RestoreDBNOCollisionAfterDrop();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPlayerPawn")
	void ReviveFromDBNO(AController* EventInstigator);

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void SafeZoneStatusChanged();

	UFUNCTION()
	void SeatChangeAnimationStopped(AFortPlayerController* VehiclePlayerController);

	UFUNCTION(Server, Reliable)
	void ServerAddStasisMode(const EFortPawnStasisMode InStasisMode, AActor* BoundStasisInstigator, const FGameplayTag& InStasisGameplayTag, const FGameplayTagContainer& AllowedActionTags);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerChooseGender(EFortCustomGender::Type Gender);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerChoosePart(EFortCustomPartType::Type Part, UCustomCharacterPart* ChosenCharacterPart);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCycleAccessoryColorSwatch(EFortCustomPartType::Type Part, bool bNext);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCycleColorSwatch(EColorSwatchType SwatchType, bool bNext);

	UFUNCTION(Server, Reliable)
	void ServerCyclePart(EFortCustomPartType::Type Part, bool bNextPart);

	UFUNCTION(Server, Reliable)
	void ServerDropCarriedPlayer();

	UFUNCTION(Server, Unreliable)
	void ServerEmoteSecondaryFirePressed();

	UFUNCTION(Server, Reliable)
	void ServerEnterStasis(EFortPawnStasisMode InStasisMode);

	UFUNCTION(Server, Reliable)
	void ServerEquipLastWeaponOrGadget(bool bForce);

	UFUNCTION(BlueprintCallable)
	void ServerHandlePickup(AFortPickup* Pickup, float InFlyTime, const FVector InStartDirection, bool bPlayPickupSound);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerHandlePickupInfo(AFortPickup* Pickup, FFortPickupRequestInfo Params);

	UFUNCTION(Server, Reliable)
	void ServerHoistDBNOPlayer(AFortPlayerPawn* InDBNOHoistee);

	UFUNCTION(Server, Reliable)
	void ServerInterrogateDBNOPlayer(AFortPlayerPawn* InDBNOHoistee);

	UFUNCTION(BlueprintCallable, Category="AthenaMovement")
	AFortAthenaVehicle* ServerOnExitVehicle(ETryExitVehicleBehavior ExitForceBehavior = ETryExitVehicleBehavior::ForceOnBlocking, const bool bDestroyVehicleWhenForced = true);

	UFUNCTION(Server, Unreliable)
	void ServerPlayUnableToPerformActionMontage();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerResetAbilitySystemComponent();

	UFUNCTION(Server, Reliable)
	void ServerRespawnFromDBNO();

	UFUNCTION(Server, Reliable)
	void ServerReviveFromDBNO(AController* EventInstigator);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerSendAimbotDetectionStatus(const TArray<uint8>& Payload);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAimbotDetection(bool bEnableDetection);

	UFUNCTION(Server, Reliable)
	void ServerSetAttachment(FRepFortMeshAttachment Attachment);

	UFUNCTION(Server, Reliable)
	void ServerStartGliderSwap();

	UFUNCTION(Server, Reliable)
	void ServerStopGliderSwap();

	UFUNCTION(Server, Reliable)
	void ServerThrowCarriedPlayer();

	UFUNCTION(Server, Reliable)
	void ServerToggleBodyType();

	UFUNCTION(Server, Reliable)
	void ServerToggleGender();

	UFUNCTION(BlueprintCallable, Category="Rendering", meta=(DisplayName="Set Actor Hidden In Game With Effect", Keywords="Visible Hidden Show Hide"))
	virtual void SetActorHiddenInGameWithGameplayEffect(bool bNewHidden, const TSubclassOf<UGameplayEffect>& HidePawnGameplayEffectClass, bool bRemoveAllOfThisTag = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Rendering", meta=(DisplayName="Set Actor Hidden In Game With Tag", Keywords="Visible Hidden Show Hide"))
	virtual void SetActorHiddenInGameWithTag(const bool bNewHidden, const FGameplayTag HidePawnGameplayTag, AActor* BoundHidingInstigator = nullptr, const bool bRemoveAllOfThisTag = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool SetAssembledMeshSchemasCosmetic(TArray<UAssembledMeshSchema*> AssembledMeshSchemas);

	UFUNCTION(BlueprintCallable, Category="Balloon")
	void SetBalloonRope(ABuildingGameplayActor* InBalloonRope);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void SetCanSlide(bool bCanSlide);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Character Part")
	virtual bool SetCharacterPartVisibility(EFortCustomPartType::Type InPartType, bool bNewVisibility, bool bPropagateToChildren);

	UFUNCTION(BlueprintCallable)
	void SetChuteAction(EChuteActions::Type InChuteAction);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetClientObservedStatsFromAnotherPawn(AFortPlayerPawn* OtherPawn);

	UFUNCTION(BlueprintCallable)
	void SetCrouch(const bool bNewValue, const bool bAttemptToSlide = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AthenaPawn")
	void SetCustomMeshHeightAdjustTarget(int32 HeightAdjust, int32 LerpSpeed);

	UFUNCTION(BlueprintCallable, Category="Armored Interface")
	void SetEquippedArmoredInterface(TScriptInterface<IFortArmoredInterface> InInterface);

	UFUNCTION(BlueprintCallable, Category="Facial")
	void SetFacialTypeOverride(EFortFacialAnimTypes NewType);

	UFUNCTION(BlueprintImplementableEvent)
	void SetFirstPersonCamera(bool bNewUseFirstPersonCamera);

	UFUNCTION(BlueprintCallable, Category="FortPlayerPawn")
	void SetForceMoveRelativeToCameraRotation(bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="Lighting")
	void SetFortPlayerPawnLightingChannels(bool bChannel0, bool bChannel1, bool bChannel2);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Spawn")
	void SetHomeActor(AActor* NewActor);

	UFUNCTION(BlueprintCallable, Category="SlipperyMovement")
	void SetInSlipperyMovement(bool bIsSlippery);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetIsInFrontEndHologram(bool bInFrontEndHologram);

	UFUNCTION(BlueprintCallable)
	virtual void SetIsParachuteForcedOpen(bool bNewIsParachuteForcedOpen);

	UFUNCTION(BlueprintCallable, Category="Balloon")
	void SetNumActiveBalloons(int32 NewBalloonCount);

	UFUNCTION(BlueprintCallable, Category="AthenaMovement")
	void SetPendingSkydiveLaunch(bool bPending);

	UFUNCTION(BlueprintCallable, Category="Tether")
	void SetPendingTetherLaunch(float Amount);

	UFUNCTION(BlueprintCallable, Category="Customization")
	void SetPetType(const UAthenaPetItemDefinition* PetToCreate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PropHunt")
	void SetPossessedProp(ABuildingGameplayActorPlayerPropAttachment* InPossessedProp);

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void SetPreviousPosition(FVector OldPosition);

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void SetPreviousVelocity(FVector OldVelocity);

	UFUNCTION(BlueprintCallable)
	void SetScalarParamOnOverriddenMaterials(const FName ParamName, float Value);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Stasis")
	void SetStasisMode(EFortPawnStasisMode InStasisMode);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Tether")
	void SetTetherPawn(APawn* InTetherPawn);

	UFUNCTION(BlueprintCallable)
	void SetTetherRopeRodMesh(USkeletalMesh* InMesh);

	UFUNCTION(BlueprintCallable)
	void SetTextureParamOnOverriddenMaterials(const FName ParamName, UTexture* Value);

	UFUNCTION(BlueprintCallable)
	void SetThrownItemTrajectoryHitResult(const FHitResult& InHitResult);

	UFUNCTION(BlueprintCallable)
	void SetTransformationMontage(UAnimMontage* CurrentMontage, UAnimMontage* FutureMontage, float StartTime);

	UFUNCTION(BlueprintCallable)
	void SetVectorParamOnOverriddenMaterials(const FName ParamName, const FLinearColor& Value);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void SetVehicleOverrideExit(const bool bIgnoreLaunch);

	UFUNCTION(BlueprintCallable, Category="AnimSets")
	void SetWeaponOverrideAnimSet(UFortWeaponAnimSet* WeaponOverrideAnimSet);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Customization")
	bool ShouldAllowShadowStanceMaterialsForPartType(EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool ShouldDriverHaveReticle() const;

	UFUNCTION(Exec)
	void ShowTestingPredictiveInput();

	UFUNCTION(BlueprintCallable, meta=(HidePin="bRegister"))
	void SpawnNiagaraWaterComponents(const bool bRegister = true);

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void StartFloating();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="GhostMode")
	void StartGhostModeExit(const float InGhostModeExitDuration);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	bool StartPlayerDistanceTraveledTimer();

	UFUNCTION(BlueprintCallable)
	void StopCarryingPlayer(bool bFromAbilityCancel = true);

	UFUNCTION(BlueprintCallable, Category="Kairos", meta=(DeprecatedFunction, DeprecationMessage="Functionality has been stripped from the runtime."))
	void StopFacialAnimationStream();

	UFUNCTION(BlueprintCallable, Category="interact", meta=(CPP_Default_OverrideItemInteractAbilityTag="()"))
	virtual void StopItemInteractionAbility(const EItemInteractionStatus ItemInteractionStatus, const FGameplayTag OverrideItemInteractAbilityTag);

	UFUNCTION(BlueprintPure)
	bool SupportsTetheredMovement();

	UFUNCTION(BlueprintCallable)
	void SwapPawnCosmeticItemAndVariant(const FGuid& SwapId, const TArray<FFortSwapItemAndVariantData>& SwapData, bool bAllowActiveHotswap = true, EFortAppliedSwapItemAndVariantState ForcedSwapState = EFortAppliedSwapItemAndVariantState::None);

	UFUNCTION(BlueprintCallable, Category="FortMovement")
	void TemporarilyIgnoreClientMovementErrorChecksAndCorrection(const float Duration);

	UFUNCTION(Exec)
	void ToggleBodyType();

	UFUNCTION(BlueprintCallable)
	void ToggleCrouch(const bool bAttemptToSlide = false);

	UFUNCTION(Exec)
	void ToggleGender();

	UFUNCTION(BlueprintCallable, Category="FailedAction")
	void UnableToPerformAction(bool bPlayMontage, const FGameplayTagContainer& FailedReason);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnequipCurrentWeaponById(FGuid WeaponItemGuid, bool bSetWeaponAttachment);

	UFUNCTION()
	void UpdateAimbotDetectionStatus();

	UFUNCTION(BlueprintCallable)
	void UpdateGameStateModifiedGravity(float GravityMultiplier);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void UpdatePlayerDistanceTraveled();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortMovement")
	void UpdatePreviousPositionAndVelocity(float DeltaSeconds, FVector OldLocation, FVector OldVelocity);

	UFUNCTION(BlueprintPure, Category="Zipline")
	bool WantsToGoFromVehicleToZipline() const;

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticMeshApplied(FOnCosmeticMeshAppliedBP Delegate, FDelegateHandleController& DelegateHandleController_Out);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyStruct", Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticMeshAppliedWithAnyStruct(FOnCosmeticMeshAppliedBPWithAnyStruct Delegate, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticPartApplied(FOnCosmeticPartAppliedBP Delegate, bool SkipNullMesh, FDelegateHandleController& DelegateHandleController_Out);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyStruct", Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticPartAppliedWithAnyStruct(FOnCosmeticPartAppliedBPWithAnyStruct Delegate, bool SkipNullMesh, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticsApplied(FOnCosmeticsAppliedBP Delegate, FDelegateHandleController& DelegateHandleController_Out);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyStruct", Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticsAppliedWithAnyStruct(FOnCosmeticsAppliedBPWithAnyStruct Delegate, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticSpecificPartApplied(FOnCosmeticPartAppliedBP Delegate, bool SkipNullMesh, EFortCustomPartType::Type PartType, FDelegateHandleController& DelegateHandleController_Out);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyStruct", Namespace="Fortnite.Cosmetics"))
	void WhenCosmeticSpecificPartAppliedWithAnyStruct(FOnCosmeticPartAppliedBPWithAnyStruct Delegate, bool SkipNullMesh, EFortCustomPartType::Type PartType, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct);

	UPROPERTY(ReplicatedUsing=OnRep_VehicleInputStateReliableForReplay)
	FFortAthenaVehicleInputStateReliable VehicleInputStateReliable;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Gameplay")
	uint8 bIsNearSafeZoneEdge : 1;

	UPROPERTY(Transient)
	uint8 bPlayingSafeZoneEffects : 1;

	UPROPERTY()
	uint8 bDoSafeZoneCleanup : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	uint8 bIsSwimmingAnimLayerLinked : 1;

	UPROPERTY()
	uint8 bIsSwimmingAnimLayerPendingRemove : 1;

	UPROPERTY(Transient)
	uint8 bIsSprintJump : 1;

	UPROPERTY(Transient)
	uint8 bHasDisableSprintTag : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_IsTacticalSprinting, Category="FortPlayerPawn")
	uint8 bIsTacticalSprinting : 1;

	UPROPERTY(Transient)
	uint8 bDisableSwimSprintCancel : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Gameplay")
	uint8 bIsWaterJump : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Gameplay")
	uint8 bIsWaterSprintBoost : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Gameplay")
	uint8 bIsWaterSprintBoostPending : 1;

	UPROPERTY(Transient)
	uint8 bPlayingPassengerToPassengerAnimation : 1;

	UPROPERTY(Transient)
	uint8 bPlayingDriverToPassengerAnimation : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_IsTargeting, Category="Animation")
	uint8 bIsTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Animation")
	uint8 bIsTargetingConsumableThrow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Animation")
	uint8 bIsSwappingCharacterParts : 1;

	UPROPERTY(Transient)
	uint8 bBalloonMovementActivated : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerPawn")
	uint8 bIsScriptedBot : 1;

	UPROPERTY(Config)
	uint8 bBuildHotfix : 1;

	UPROPERTY(EditAnywhere, Category="Lighting")
	FLightingChannels FortPlayerPawnLightingChannels;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StasisModes)
	EFortPawnStasisMode StasisMode;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StasisModes)
	TArray<EFortPawnStasisMode> StasisModes;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPlayerPawn")
	TEnumAsByte<EFortBuildingState::Type> BuildingState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AccelerationZPack)
	int8 AccelerationZPack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> ParachuteDirectionalSpeedMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> SkydivingDirectionalSpeedMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> BallooningDirectionalSpeedMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> DirectionalSpeedMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> ThirdPersonSpeedMultiplierCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> OverrideWalkDirectionalSpeedMultiplierCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> OverrideRunDirectionalSpeedMultiplierCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMovement")
	TObjectPtr<UCurveFloat> OverrideCrouchDirectionalSpeedMultiplierCurve;

	UPROPERTY(BlueprintReadWrite, Category="AthenaMovement")
	bool bIsThirdPersonModeEnabled;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float LastCustomizationTimestamp;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float MinimumTimeBetweenSteps;

	UPROPERTY(Transient)
	float LastStepTime;

	UPROPERTY(BlueprintAssignable)
	FOnFootstepEvent OnFootstepEvent;

	UPROPERTY(BlueprintAssignable)
	FOnPawnEnterWater OnPawnEnterWater;

	UPROPERTY(BlueprintAssignable)
	FOnPawnExitWater OnPawnExitWater;

	UPROPERTY(BlueprintAssignable)
	FOnPawnExitSwinging OnPawnExitSwinging;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPawn")
	float CurrentPawnSquaredSpeedXY;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPawn")
	FRotator CurrentPawnVelXYRot;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPawn")
	float CurrentPawnSquaredSpeed;

	UPROPERTY(ReplicatedUsing=OnRep_IsInWaterVolume)
	bool bIsInWaterVolume;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	FScalableFloat ShallowWaterVolumeSurfaceTraceStartOffsetZ;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	FScalableFloat ShallowWaterVolumeSurfaceTraceEndOffsetZ;

	UPROPERTY(Config)
	bool bNotifyBlueprintWhenLandscapeTeleporting;

	UPROPERTY(Transient)
	uint8 bForceMoveRelativeToCameraRotation : 1;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_IsEmoteLeader, Category="Emote")
	uint8 bIsEmoteLeader : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Emote")
	uint8 bShouldSyncAnimationWithEmoteLeader : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Emote")
	uint8 bShouldJitterAnimationSyncWithEmoteLeader : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Emote")
	uint8 bDoubleFileEmoteSecondLine : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Emote")
	uint8 bEmoteUsesSecondaryFire : 1;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_LockGroupEmoteLeaderRotation, Category="Emote")
	uint8 bLockGroupEmoteLeaderRotation : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Emote")
	int32 EmoteBandLeaderIndex;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_GroupEmoteLookTarget, Category="Emote")
	TObjectPtr<AFortPlayerPawn> GroupEmoteLookTarget;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Emote")
	TObjectPtr<AFortPlayerPawn> GroupEmoteTailTarget;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Emote")
	TArray<TObjectPtr<AFortPlayerPawn>> GroupEmoteFollowers;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Emote")
	float GroupEmoteAnimOffset;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Emote")
	float GroupEmoteLeaderRotationYawOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Emote")
	FRotator GroupEmoteLookTargetRotationLeader;

	UPROPERTY(Config)
	float GroupEmoteMaximumZDifference;

	UPROPERTY(BlueprintAssignable)
	FOnGroupEmoteSyncValueChanged OnGroupEmoteSyncValueChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnGroupEmoteFollowerJoined OnGroupEmoteFollowerJoined;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnGroupEmoteFollowerLeft OnGroupEmoteFollowerLeft;

	UPROPERTY(BlueprintAssignable)
	FOnGroupEmoteSecondaryFirePressed OnGroupEmoteSecondaryFirePressed;

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_GroupEmoteSyncValue, Category="FortPlayerPawn")
	uint8 GroupEmoteSyncValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	uint8 GroupEmoteSoundValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	uint8 GroupEmoteParticleValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Animation")
	TObjectPtr<UAnimMontage> TransformationMontage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Animation")
	float TransformationMontageStartTime;

	UPROPERTY(ReplicatedUsing=OnRep_CustomMeshHeightAdjustTarget)
	uint16 ReplicatedCustomMeshHeightAdjustTarget;

	UPROPERTY(Config)
	float UnburrowLaunchXYSpeed;

	UPROPERTY(Config)
	float UnburrowLaunchZSpeed;

	UPROPERTY()
	TSubclassOf<UGameplayEffect> SafeZoneAppliedGE;

	UPROPERTY(Transient)
	float SprintCancelTime;

	UPROPERTY(Transient)
	bool bIsTouchingTouchpadSimple;

	UPROPERTY(Transient)
	float WaterSprintBoostAllowedTimer;

	UPROPERTY(Transient, Replicated)
	bool bCanPredictJumpApex;

	UPROPERTY(Transient)
	float EmoteStartTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	float EmoteRandomNum;

	UPROPERTY(Transient)
	bool bPlayingPassengerToDriverAnimation;

	UPROPERTY(Transient)
	float VehicleSpeedAtTimeOfJump;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_UpdateContextTracker)
	TObjectPtr<AFortPlayerControllerGameplay> InteractingPCRep;

	UPROPERTY(Transient)
	TObjectPtr<AActor> VehicleLastTick;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleStateChangeEvent OnVehicleStateChangedEvent;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnUIGameplayCueEvent OnUIGameplayCue;

	UPROPERTY(BlueprintAssignable, Category="Cosmetics")
	FOnPetAddedOrRemoved OnPetAddedOrRemoved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPawn", meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_Tether> TetherComponent;

	UPROPERTY(Transient)
	float PendingTetherLaunch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tether")
	float TetherJumpLastTime;

	UPROPERTY(Config)
	bool bSupportsTetheredMovement;

	UPROPERTY(BlueprintReadOnly, Category="Balloon")
	TObjectPtr<ABuildingGameplayActor> BalloonRope;

	UPROPERTY(BlueprintAssignable, Category="PropHunt")
	FOnPossessedProp OnPossessedProp;

	UPROPERTY(Transient)
	int64 SlopeCameraOffsetFrameCounter;

	UPROPERTY(Transient)
	FVectorRK4SpringInterpolator SlopeCameraOffsetInterpolator;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	FVector LargeBodyTypeTargetingOffset;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> VehicleInputComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TObjectPtr<UAnimMontage> BluePrintPlaceAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TObjectPtr<UAnimMontage> BluePrintEditAnimation;

	UPROPERTY(BlueprintAssignable)
	FCharacterPartChanged OnPartChanged;

	UPROPERTY(BlueprintAssignable)
	FCharacterPartVisibilityChanged OnManagedPartVisibilityChanged;

	UPROPERTY(BlueprintAssignable)
	FFortPlayerPawnDelegate OnPostResIn;

	UPROPERTY(BlueprintAssignable)
	FMaterialOverrideAppliedDelegate OnMaterialOverrideApplied;

	UPROPERTY(BlueprintAssignable)
	FMaterialOverrideClearedDelegate OnMaterialOverrideCleared;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> OnCrouchStartSound;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> OnCrouchEndSound;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSetOverride;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortLocomotionAnimAsset> LocomotionAnimAssetOverride;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPickup>> QueuedAutoPickups;

	UPROPERTY()
	TArray<FIgnoreCollisionActor> IgnoreActors;

	UPROPERTY(Config)
	float PositionCaptureIntervalForDistanceTraveledAccumulation;

	UPROPERTY(ReplicatedUsing=OnRep_DBNOHoisterData)
	FFortDBNOCarryHoisterData DBNOHoisterData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DBNOHoistee)
	TObjectPtr<AFortPlayerPawn> DBNOHoistee;

	UPROPERTY(EditAnywhere, Category="AnimSets")
	TObjectPtr<UFortWeaponAnimSet> DBNOHoisterAnimSet;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float ThrowCarriedPlayerStrengthXY;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float ThrowCarriedPlayerStrengthZ;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float DropCarriedPlayerForwardOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float DropCarriedPlayerHeightOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float DropCarriedPlayerTraceHeight;

	UPROPERTY(Config)
	bool bAllowDBNOCarry;

	UPROPERTY(Config)
	bool bAllowDBNOCarryEnemies;

	UPROPERTY(Transient)
	bool bIsBeingDBNOCarried;

	UPROPERTY(Transient)
	bool bIsDBNOCarrying;

	UPROPERTY(Transient)
	bool bRequestedThrowCarriedPlayer;

	UPROPERTY(BlueprintAssignable)
	FOnDBNOHoisterChanged OnDBNOHoisterChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerRevivedFromDBNO OnRevivedFromDBNODelegate;

	UPROPERTY(BlueprintAssignable)
	FOnRevivePlayerFromDBNO OnRevivePlayerFromDBNODelegate;

	UPROPERTY(BlueprintAssignable)
	FNewPlayerStateDelegate OnNewPlayerState;

	UPROPERTY(BlueprintAssignable)
	FAbilitySystemInitializedDelegate OnAbilitySystemComponentInitialized;

	UPROPERTY(BlueprintAssignable)
	FOnPreInvalidateAbilitySystemComponent OnPreInvalidateAbilitySystemComponent;

	UPROPERTY(BlueprintAssignable, Category="Customization")
	FOnFinishedCharacterCustomization OnFinishedCharacterCustomization;

	UPROPERTY(BlueprintAssignable, Category="Input")
	FOnCrouchInputJustPressed OnCrouchInputJustPressed;

	UPROPERTY(Transient, Replicated)
	uint32 PlayerStatus;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AccelerationPack)
	uint16 AccelerationPack;

	UPROPERTY(ReplicatedUsing=OnRep_RepAnimMontageStartSection)
	int32 RepAnimMontageStartSection;

	UPROPERTY()
	uint8 bUseControllerRotationYawToRestore : 1;

	UPROPERTY(BlueprintAssignable)
	FOnBeginSkydivingEvent OnBeginSkydivingEvent;

	UPROPERTY(BlueprintAssignable)
	FOnEndSkydivingEvent OnEndSkydivingEvent;

	UPROPERTY(BlueprintAssignable)
	FOnBeginParachuteMovementEvent OnBeginParachuteMovementEvent;

	UPROPERTY(BlueprintAssignable)
	FParachuteSpawnedDelegate OnParachuteSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnEndParachuteMovementEvent OnEndParachuteMovementEvent;

	UPROPERTY(BlueprintAssignable)
	FOnBallooningGravityCeilingChanged OnBallooningGravityCeilingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnEnteredAircraft OnEnteredAircraft;

	UPROPERTY(BlueprintAssignable)
	FOnStopSliding OnStopSliding;

	UPROPERTY(BlueprintAssignable, Category="Game|Player", meta=(Keywords="Pawn Possess"))
	FOnPlayerPawnPosessionChanged OnPawnPossessed;

	UPROPERTY(BlueprintAssignable, Category="Game|Player", meta=(Keywords="Pawn Unpossess"))
	FOnPlayerPawnPosessionChanged OnPawnUnpossessed;

	UPROPERTY(BlueprintAssignable, Category="Game|Player")
	FOnEmoteInteracted OnEmoteInteracted;

	UPROPERTY(BlueprintAssignable)
	FOnSafeZoneOccupancyChanged OnSafeZoneOccupancyChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectChanged OnHeldObjectPickedUp;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectChanged OnHeldObjectDropped;

	UPROPERTY()
	TObjectPtr<UFortPawnScriptedBehavior> BotScriptedBehavior;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortWaterBodyActor>> IgnoredWaterBodies;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUnderwaterDamageComponent> UnderwaterDamageComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SlipperyMovement")
	FSlipperySlopeParams SlipperySlopeParams;

	UPROPERTY()
	TObjectPtr<UAthenaGliderItemDefinition> GliderClass;

	UPROPERTY(Transient)
	float LastQuickBarSwitchRequestTime;

	UPROPERTY(Transient)
	float CrouchStartTime;

	UPROPERTY(Transient)
	float CrouchEndTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortPlayerPawn")
	float CrouchLerpTime;

	UPROPERTY(Config)
	float MeleeAbilityCooldown;

	UPROPERTY(Config)
	bool bDisallowInterrogation;

	UPROPERTY(Config)
	bool bDisallowInterrogationOnNPC;

	UPROPERTY(Config)
	bool bDisallowInterrogationCreative;

	UPROPERTY()
	uint8 bHideBodyOnDeathRequested : 1;

	UPROPERTY()
	TMap<FName, FFortPlayerPawnObjectReference> CachedReferencesByName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_PlayerInWater;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_PlayerInWaterSurfaceSwimming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerInWaterBasicAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerInWaterSwimmingAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerWaterHandSplashAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerWaterFootSplashAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerWaterLargePlayerSplashAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerWaterBoostAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FName FootSplashLeftSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FName FootSplashRightSocketName;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerStandingInWater;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerSwimmingInWater;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerHandSplashInWater;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerFootSplashInWaterLeft;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerFootSplashInWaterRight;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerJumpSplashInWater;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerWaterBoost;

	UPROPERTY(Transient)
	uint8 bWaterFootSplashActive : 1;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings")
	uint8 bEnableWaterInteractionEffects : 1;

	UPROPERTY(BlueprintAssignable)
	FOnActivateAbility OnActivateAbility;

	UPROPERTY(BlueprintAssignable)
	FOnFiringRangedWeapon OnFiringRangedWeapon;

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fort Player Pawn")
	void AddAbilityAITarget(AFortAIPawn* InTarget);

	UFUNCTION()
	void AITargetDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintCallable, Category="Parachute", meta=(DisplayName="CloseParachuteAndFall"))
	void BP_CloseParachuteAndFall();

	UFUNCTION(BlueprintCallable, Category="Parachute", meta=(DisplayName="ForceLockParachuteOpen"))
	void BP_ForceLockParachuteOpen(bool bLocked);

	UFUNCTION(BlueprintCallable, Category="Parachute", meta=(DisplayName="ForceOpenParachute"))
	void BP_ForceOpenParachute();

	UFUNCTION(BlueprintCallable, Category="Parachute", meta=(DisplayName="OpenParachute"))
	void BP_OpenParachute();

	UFUNCTION(Client, Reliable, Category="Zipline")
	void ClientForceZiplineState(const FZiplinePawnState& InZiplineState);

	UFUNCTION(Client, Reliable)
	void ClientUnequipCurrentWeaponById(FGuid WeaponItemGuid, bool bSetWeaponAttachment);

	UFUNCTION(BlueprintCallable, Category="Interact")
	void EndedInteractSearch();

	UFUNCTION(BlueprintCallable, Category="Parachute")
	void ForceOpenParachuteAndOverrideGlider(const UAthenaGliderItemDefinition* InGliderOverride, bool bResetGliderOverrideOnLanding = true, bool bForceIntoGliderRedeploy = true);

	UFUNCTION(BlueprintPure, Category="Camera")
	bool GetUseViewRotationForCameraOrigin() const;

	UFUNCTION(BlueprintPure, Category="Parachute")
	bool IsParachuteLockedOpen() const;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastUpdateVehicleInputStateReliable(FFortAthenaVehicleInputStateReliable ReliableInput);

	UFUNCTION()
	void OnBoundHidingInstigatorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnBoundStasisInstigatorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCharacterPartsReinitialized();

	UFUNCTION(BlueprintImplementableEvent, Category="Parachute")
	void OnOpenParachute(bool& bConsumeEvent);

	UFUNCTION()
	void OnPostPhysicsRotation(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds);

	UFUNCTION()
	void OnRemoveZiplineFromIgnoreWhenMovingTimerExpired();

	UFUNCTION()
	void OnRep_AppliedSwaps();

	UFUNCTION()
	void OnRep_BaseCosmeticLoadout();

	UFUNCTION()
	void OnRep_bDisabledTetheringSupport();

	UFUNCTION()
	void OnRep_bHasStartedFloating();

	UFUNCTION()
	virtual void OnRep_ControlledRCPawn();

	UFUNCTION()
	void OnRep_FacialTypeOverride();

	UFUNCTION()
	void OnRep_GliderOverride(const TArray<UAthenaGliderItemDefinition*>& OldSet);

	UFUNCTION()
	void OnRep_GroupEmoteLookTarget();

	UFUNCTION()
	void OnRep_IsEmoteLeader();

	UFUNCTION()
	void OnRep_IsParachuteForcedOpen();

	UFUNCTION()
	virtual void OnRep_IsParachuteOpen(bool bPreviousState);

	UFUNCTION()
	void OnRep_IsSkydiving(bool bPreviousState);

	UFUNCTION()
	void OnRep_IsSkydivingFromBus();

	UFUNCTION()
	void OnRep_IsTargeting();

	UFUNCTION()
	void OnRep_LockGroupEmoteLeaderRotation();

	UFUNCTION()
	void OnRep_MaterialOverrides();

	UFUNCTION()
	void OnRep_NetMovementPrioritized(bool bOldNetMovementPrioritized);

	UFUNCTION()
	void OnRep_NPCRetargetingInfo();

	UFUNCTION()
	void OnRep_ParachuteLockedOpen();

	UFUNCTION()
	virtual void OnRep_PossessedProp(ABuildingGameplayActorPlayerPropAttachment* OldProp);

	UFUNCTION()
	void OnRep_RepAnimMontageStartSection();

	UFUNCTION()
	void OnRep_ReplicatedAnimMontage();

	UFUNCTION()
	void OnRep_ReplicatedInGliderRedeploy();

	UFUNCTION()
	void OnRep_ReplicatedIsInSlipperyMovement();

	UFUNCTION()
	virtual void OnRep_StoredControlRotation();

	UFUNCTION()
	void OnRep_WaitingForEmoteInteraction();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Parachute")
	void PopGliderOverride(const UAthenaGliderItemDefinition* InGliderToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Parachute")
	void PushGliderOverride(const UAthenaGliderItemDefinition* InGliderOverride);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fort Player Pawn")
	void RemoveAbilityAITarget(AFortAIPawn* InTarget);

	UFUNCTION(Server, Reliable, WithValidation, Category="Zipline")
	void ServerSendZiplineState(const FZiplinePawnState& InZiplineState);

	UFUNCTION(Server, Reliable)
	void ServerUnmarkRespawned();

	UFUNCTION(Server, Reliable)
	void ServerUpdateVehicleInputStateReliable(FFortAthenaVehicleInputStateReliable ReliableInput);

	UFUNCTION(Server, Unreliable)
	void ServerUpdateVehicleInputStateUnreliable(FFortAthenaVehicleInputStateUnreliable ReliableInput, float Timestamp);

	UFUNCTION(Server, Reliable, Category="Zipline")
	void ServerVehicleEjectForZiplining();

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetIsWaitingForEmoteInteraction(bool bWaitingForEmoteInteraction);

	UFUNCTION(BlueprintPure, Category="Death")
	bool ShouldPlayDeathAnimation();

	UFUNCTION(BlueprintCallable, Category="Interact")
	void StartedInteractSearch();

	UFUNCTION()
	void VerifySkydivingMatchesServer();

	UPROPERTY(Transient, Replicated)
	uint8 CachedTeamControllingRC;

	UPROPERTY(Replicated)
	uint8 BalloonActiveCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	uint8 bParachuteDeployFixedVerticalDistance : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSkydiving, Category="Parachute", meta=(ScriptName="IsSkydivingValue"))
	bool bIsSkydiving;

	UPROPERTY(ReplicatedUsing=OnRep_IsParachuteOpen)
	bool bIsParachuteOpen;

	UPROPERTY(Transient)
	uint8 bLocalIsSkydiving : 1;

	UPROPERTY()
	uint8 bLocalIsParachuteForcedOpen : 1;

	UPROPERTY(ReplicatedUsing=OnRep_IsParachuteForcedOpen)
	uint8 bIsParachuteForcedOpen : 1;

	UPROPERTY(ReplicatedUsing=OnRep_IsSkydivingFromBus)
	uint8 bIsSkydivingFromBus : 1;

	UPROPERTY(Replicated)
	uint8 bIsSkydivingFromLaunchPad : 1;

	UPROPERTY(Transient)
	uint8 bPendingSkydiveLaunch : 1;

	UPROPERTY(Transient)
	uint8 bIsInSlipperyMovement : 1;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedIsInSlipperyMovement)
	uint8 bReplicatedIsInSlipperyMovement : 1;

	UPROPERTY(Transient)
	uint8 bIsBelowAutoDeployTestHeight : 1;

	UPROPERTY(Replicated)
	uint8 bIsProxySimulationTimedOut : 1;

	UPROPERTY(Transient)
	uint8 bIsPedestalHero : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedInGliderRedeploy)
	uint8 bInGliderRedeploy : 1;

	UPROPERTY(Transient)
	uint8 bLocalInGliderRedeploy : 1;

	UPROPERTY(Transient)
	uint8 bDestructionGuard : 1;

	UPROPERTY(Transient)
	uint8 bBeingRepossessed : 1;

	UPROPERTY(EditDefaultsOnly, Category="InitPawn")
	uint8 bInitAbilitySystemComponentFromPlayerState : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StartedInteractSearch)
	uint8 bStartedInteractSearch : 1;

	UPROPERTY(Transient)
	uint8 bSignificanceLODDirty : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsUsingJetpack : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(Transient)
	uint8 bShowingOverdriveEffect : 1;

	UPROPERTY(Replicated)
	uint8 bIsRespawning : 1;

	UPROPERTY(Replicated)
	uint8 bIsRespawningInAir : 1;

	UPROPERTY(Transient)
	uint8 bInitializedPostRepPlayerState : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="PawnSettings")
	uint8 bHasWaterParticleSystem : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bCanShowDefaultSkin : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bDisabledTetheringSupport)
	uint8 bDisabledTetheringSupport : 1;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> HeldObject;

	UPROPERTY(Transient)
	float JumpLastActivatedTime;

	UPROPERTY(Transient)
	FVector PreviousPosition;

	UPROPERTY(Transient)
	FVector PreviousVelocity;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsInAnyStorm, Category="Gameplay")
	uint8 bIsInAnyStorm : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsInsideSafeZone, Category="Gameplay")
	uint8 bIsInsideSafeZone : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slide")
	TSubclassOf<UGameplayEffect> DisableSlideGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> SelfReviveGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> TeammateReviveGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	FScalableFloat SetByCallerReviveHealth;

	UPROPERTY(EditDefaultsOnly, Category="DBNO")
	FName DBNOInteractionCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Category="DBNO")
	FVector DBNOInteractionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="DBNO")
	float DBNODeferTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> DBNOInteractCollisionComponent;

	UPROPERTY(EditDefaultsOnly, Category="DBNO")
	FGameplayTag EventReviveTag;

	UPROPERTY(BlueprintReadWrite, Category="Noise")
	float AggroRangeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DBNO")
	float SetByCallerReviveSignalInStorm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DBNO")
	FScalableFloat DBNOHorizontalTetherMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DBNO")
	FScalableFloat DBNOVerticalTetherMultiplier;

	UPROPERTY(Replicated)
	TArray<FGameplayAbilitySpecHandle> StasisAbilityHandles;

	UPROPERTY()
	TScriptInterface<IFortArmoredInterface> ArmoredInterface;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata> LastBuildingMetadata;

	UPROPERTY(ReplicatedUsing=OnRep_bHasStartedFloating)
	bool bHasStartedFloating;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ZiplineState)
	FZiplinePawnState ZiplineState;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FCurveTableRowHandle ZiplineJumpDampening;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FCurveTableRowHandle ZiplineJumpStrength;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineJumpActivateDelay;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat ZiplineRentryProtectionDelay;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	float ZiplineSocketZOffset;

	UPROPERTY(BlueprintAssignable)
	FZiplineStateChanged ZiplineStateChanged;

	UPROPERTY(BlueprintAssignable)
	FZiplinePostBegin ZiplinePostBegin;

	UPROPERTY(Transient)
	float ZiplineSpeedFactorTarget;

	UPROPERTY(Transient)
	float ZiplineSpeedFactor;

	UPROPERTY(EditDefaultsOnly, Category="Water")
	FScalableFloat EnableSwimSprintDiveCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Water")
	FScalableFloat SwimSprintDiveCooldown;

	UPROPERTY(EditDefaultsOnly, Category="Water")
	FScalableFloat SwimDiveBoostTimeThreshold;

	UPROPERTY(Transient)
	float ClientSwimDiveInputTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Action")
	TObjectPtr<UAnimMontage> UnableToPerformActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Action")
	TObjectPtr<USoundBase> UnableToPerformActionSound;

	UPROPERTY(EditAnywhere, Config, Category="FortPlayerPawn")
	float MoveSoundStimulusBroadcastInterval;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PossessedProp)
	TObjectPtr<ABuildingGameplayActorPlayerPropAttachment> PossessedProp;

	UPROPERTY(BlueprintAssignable)
	FOnStartedInteractSearch OnStartedInteractSearch;

	UPROPERTY(BlueprintAssignable)
	FOnEndedInteractSearch OnEndedInteractSearch;

	UPROPERTY(BlueprintAssignable)
	FOnInstantInteractSearch OnAttemptedInstantInteractSearch;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	FName EmoteInteractionCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	FVector EmoteInteractionBoxExtent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> EmoteInteractCollisionComponent;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BlueprintPaperMID;

	UPROPERTY(Transient)
	FTimeline BlueprintPaperPulseTimeline;

	UPROPERTY(Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType", EditInline="true"))
	TObjectPtr<UCustomColorComponent> AccessoryColorSwatchHandler[7];

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType", EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> CharacterPartSkeletalMeshComponents[7];

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerCharm>> CharacterCharmActors;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	int8 CharacterPartSMHiddenRefCount[7];

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BaseCosmeticLoadout, Category="FortPlayerPawn")
	FFortAthenaLoadout BaseCosmeticLoadout;

	UPROPERTY(Transient)
	FFortAthenaLoadout AppliedCosmeticLoadout;

	UPROPERTY(Transient)
	FFortReconstructibleAthenaLoadout CachedLoadoutForCSV;

	UPROPERTY(ReplicatedUsing=OnRep_AppliedSwaps)
	TArray<FFortAppliedSwapItemAndVariantData> AppliedSwaps;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NPCRetargetingInfo)
	TObjectPtr<UFortAIPawnCustomizationDefinition> NPCRetargetingInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AnimBPOverride)
	TSubclassOf<UAnimInstance> AnimBPOverride;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> OriginalAnimBP;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FootstepBankOverride)
	TObjectPtr<UFortFootstepAudioBank> FootstepBankOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFortFootstepAudioBank> OriginalFootstepBank;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	int32 CachedFootStepIndex;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AnimLayersOverride)
	TArray<TSubclassOf<UAnimInstance>> AnimLayersOverride;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UAnimInstance>> PreviousAnimLayersOverride;

	UPROPERTY(EditAnywhere, Category="Pickup")
	FScalableFloat AutoPickupDropRepickupDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CarriedObject")
	FName CarriedObjectAttachmentSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pickup")
	float PickupSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush AboveBelowMiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush FarOffMiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush DBNOMiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorSelf;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorTeammate;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorEnemy;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float MaxIndicatorVisibilityDistForEnemies;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawn")
	float MaxIndicatorVisibilityDistForAllies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	TObjectPtr<UParticleSystem> SpawnParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn")
	TObjectPtr<USoundBase> SpawnSound;

	UPROPERTY(Transient)
	uint8 bIsLocalPlayer : 1;

	UPROPERTY(Transient)
	uint8 bDamagedEnemy : 1;

	UPROPERTY(BlueprintAssignable, Category="Damage|Combo")
	FOnDamageComboIncrement OnDamageComboIncrement;

	UPROPERTY(BlueprintAssignable, Category="Damage|Combo")
	FOnDamageComboReset OnDamageComboReset;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedAnimMontage)
	FGameplayAbilityRepAnimMontage RepAnimMontageInfo;

	UPROPERTY(ReplicatedUsing=OnRep_NetMovementPrioritized)
	uint8 bNetMovementPrioritized : 1;

	UPROPERTY(Replicated)
	FReplicatedMontagePair LandingMontagePair;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortVisibilityComponent> VisibilityComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> BlendablesPostProcessComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerPawn")
	TMap<TEnumAsByte<EFortCustomMovement::Type>, TObjectPtr<UTexture>> CustomMovementIndicators;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CurrentGliderOpenSound;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> CurrentGliderOpenAudioComponent;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CurrentGliderCloseSound;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> CurrentGliderCloseAudioComponent;

	UPROPERTY(ReplicatedUsing=OnRep_ParachuteLockedOpen)
	bool bParachuteLockedOpen;

	UPROPERTY(Transient)
	bool bLocalParachuteLockedOpen;

	UPROPERTY(ReplicatedUsing=OnRep_AttachmentMesh)
	FRepFortMeshAttachment AttachmentMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Character", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> AttachmentMeshComponent;

	UPROPERTY(Replicated)
	TObjectPtr<AFortPlayerPetRepState> PetState;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerPawn")
	TObjectPtr<AFortPlayerPet> CosmeticPetInstance;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGliderSpawnComponent> GliderSpawnComponent;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPawn", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortPlayerParachute> ParachuteAttachment;

	UPROPERTY(ReplicatedUsing=OnRep_GliderOverride)
	TArray<TObjectPtr<UAthenaGliderItemDefinition>> GliderOverrideStack;

	UPROPERTY(Transient)
	bool bResetGliderOverrideOnLanding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat ParachuteDeployTraceForGroundDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat LaunchPadParachuteDeployTraceForGroundDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat LaunchPadParachuteDeployTraceForDownwardSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat ParachuteDeployVelocityBlend;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	float ParachuteCooldownToOpen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	float ParachuteCooldownToClose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat GliderRedeployAllowedRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat GliderRedeployLateralVelocityMultiplierRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat GliderRedeployHeighLimitRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parachute")
	FScalableFloat FallOnCloseParachuteRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Balloon")
	FScalableFloat BalloonFallDamageThresholdVelocityZ;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> PreDrivingAnimBP;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> CurrentVehicleAnimLayerOverlayClass;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> CurrentSwimmingAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, Category="Swimming")
	TSubclassOf<UAnimInstance> DefaultSwimmingAnimLayerOverlayClass;

	UPROPERTY(EditDefaultsOnly, Category="Swimming")
	float TimeBeforeSwimmingLayerDeactivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPawn", meta=(EditInline="true"))
	TObjectPtr<UFortLinkedAnimGraphComponent> LinkedAnimGraphComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Export, Category="FortPlayerPawn", meta=(EditInline="true"))
	TObjectPtr<UFortPlayerAnimationComponent> AnimationComponent;

	UPROPERTY(BlueprintReadWrite, Export, Category="Parachute Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ParachuteAudioLoop;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	float ParachuteAndSkydiveAudioFadeInTime;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	float ParachuteAndSkydiveAudioFadeOutTime;

	UPROPERTY(BlueprintReadWrite, Export, Category="Parachute Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SkydiveAudioLoop;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	TObjectPtr<USoundBase> SoundOnParachuteForcedOpen;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	TObjectPtr<USoundBase> SkydivingLoop1P;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	TObjectPtr<USoundBase> SkydivingLoop3P;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	TObjectPtr<USoundBase> ParachuteOpenLoop1P;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	TObjectPtr<USoundBase> ParachuteOpenLoop3P;

	UPROPERTY(BlueprintReadWrite, Export, Category="Swimming Audio", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SwimmingAudioLoop;

	UPROPERTY(EditDefaultsOnly, Category="Swimming Audio")
	float SwimmingAudioFadeOutTime;

	UPROPERTY(EditDefaultsOnly, Category="Swimming Audio")
	float SwimmingAudioInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Swimming Audio")
	TObjectPtr<USoundBase> SoundOnSwimmingLoop;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControlledRCPawn)
	TWeakObjectPtr<AFortRemoteControlledPawnAthena> ControlledRCPawn;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StoredControlRotation)
	FRotator StoredControlRotation;

	UPROPERTY(ReplicatedUsing=OnRep_FacialTypeOverride)
	EFortFacialAnimTypes FacialTypeOverride;

	UPROPERTY(Transient)
	float GhostModeExitStartTime;

	UPROPERTY(Transient)
	float GhostModeExitDuration;

	UPROPERTY(BlueprintReadWrite, Category="FX")
	bool bFXPlayDustOnMovement;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SlidingAudioComp;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundBase> SlidingIntensitySound3P;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundBase> SlidingIntensitySound1P;

	UPROPERTY(Transient)
	float SlideAudioIntensity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_PlayerSlideLand;

	UPROPERTY(EditDefaultsOnly, Category="WeakSpots")
	FScalableFloat ConsecutiveWeakSpotResourceBonus;

	UPROPERTY(EditDefaultsOnly, Category="WeakSpots")
	FScalableFloat LastHitWeakSpotResourceBonus;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPawn", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortPawnComponent_Convert> ConvertComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPawn", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortActorComponent_Affiliation> AffiliationComponent;

private:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	bool IsWaitingForEmoteInteraction() const;

	UFUNCTION(Exec)
	void ListCharacterParts(const FString& GenderAndOrPartString = TEXT("")) const;

	UFUNCTION()
	void OnPhysicsVolumeChanged(APhysicsVolume* NewVolume);

	UFUNCTION()
	void OnRep_AttachmentMesh();

	UFUNCTION()
	void OnRep_CharPartAnimMontageInfo();

	UFUNCTION()
	void OnRep_ShallowWaterVolumeData(const FPlayerPawnShallowWaterVolumeData& PreviousShallowWaterVolumeData);

	UFUNCTION()
	void OnRep_StartedInteractSearch();

	UFUNCTION(Exec)
	void RandomizeCharacter(const FString& GenderString = TEXT(""));

	UFUNCTION(Server, Reliable)
	void ServerRootMotionInterruptNotifyStopMontage(UAnimMontage* MontageToStop);

	UFUNCTION(Exec)
	void SwitchToNextPart(const FString& PartName = TEXT(""));

	UFUNCTION(Exec)
	void SwitchToPreviousPart(const FString& PartName = TEXT(""));

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ShallowWaterVolumeData)
	FPlayerPawnShallowWaterVolumeData ShallowWaterVolumeData;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=IsInFrontEndHologram, BlueprintSetter=SetIsInFrontEndHologram, Category="Cosmetics", meta=(AllowPrivateAccess="true"))
	uint8 bIsInFrontEndHologram : 1;

	UPROPERTY(BlueprintGetter=IsWaitingForEmoteInteraction, BlueprintSetter=SetIsWaitingForEmoteInteraction, Transient, ReplicatedUsing=OnRep_WaitingForEmoteInteraction, Category="Emote", meta=(AllowPrivateAccess="true"))
	uint8 bIsWaitingForEmoteInteraction : 1;

	UPROPERTY(Transient)
	TObjectPtr<UAnimMontage> CurrentMontagerLeader;

	UPROPERTY(Transient)
	TObjectPtr<UAnimMontage> CurrentSyncedMontage;

	UPROPERTY(Config, Transient)
	uint8 bCharacterPartsCastIndirectShadows : 1;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomGender::Type> CharacterGender;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomBodyType::Type> CharacterBodyType;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentVehicle;

	UPROPERTY(Transient)
	TObjectPtr<UFortHero> Hero;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortHeroType> OvrHeroType;

	UPROPERTY(Transient)
	EFortPawnDisplayContext DisplayContext;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCustomPlayerComponent> HACK_CustomPRIComponent;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> CharacterParts[7];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType"))
	TObjectPtr<UCustomColorSwatch> CharacterColorSwatches[2];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomColorSwatch> CharacterPartColorSwatches[7];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomCharmType"))
	TObjectPtr<UAthenaCharmItemDefinition> CharacterCharms[4];

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> RequiredVariantParts;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCosmeticDataComponent> CosmeticDataComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCosmeticLoadoutComponent> CosmeticLoadoutComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn", meta=(AllowPrivateAccess="TRUE"))
	FFortAthenaLoadout CosmeticLoadout;

	UPROPERTY(Replicated)
	uint32 ServerLoadoutChangeSync;

	UPROPERTY(Config)
	bool bAllowClientLoadoutChangeSync;

	UPROPERTY(ReplicatedUsing=OnRep_MaterialOverrides)
	TArray<FFortPawnMaterialOverride> MaterialOverrides;

	UPROPERTY()
	TArray<FFortPawnMaterialOverride> LocalMaterialOverrides;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPawn", meta=(AllowPrivateAccess="TRUE"))
	TMap<TObjectPtr<USceneComponent>, FFortPawnMaterialOverrideState> MaterialOverrideStateMap;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> PreviousCharacterParts[7];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<ACustomCharacterPartModifier> CharacterPartModifiers[7];

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CharPartAnimMontageInfo)
	FFortCharacterPartsRepMontageInfo RepCharPartAnimMontageInfo;

	UPROPERTY(Transient, Replicated)
	FFortClientObservedStatArray ClientObservedStats;

	UPROPERTY(Transient, Instanced)
	UFortPawnSkeletalMeshContext* SkeletalMeshContext;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCosmeticsEarlyQRPComponent> CosmeticsEarlyQRPComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationAssetLoader> CustomizationAssetLoader;

	UPROPERTY(Transient)
	uint8 SkipStartCosmeticsPassForActor;

	UPROPERTY(Transient)
	FPreviouslyAppliedVariantData PriorVariantData;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItemDefinition>> TempWeaponsStack;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAnimNotifyState_RootMotionInterrupt>> RootMotionInterruptNotifyStack;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAnimMontage>> RootMotionInterruptMontageStack;

	UPROPERTY(Replicated)
	uint32 RemoteViewData32;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> CustomInteractionWidget;

	UPROPERTY(Transient)
	uint8 bUseViewRotationForCameraOrigin : 1;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings")
	uint8 bCanUseDefaultPartsOnLateLoad : 1;

};

UCLASS()
class UFortItemAndVariantSwapHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	static void PushCosmeticOverrideOntoPawn(AFortPlayerPawn* Pawn, UAthenaCosmeticItemDefinition* Cosmetic);

};

