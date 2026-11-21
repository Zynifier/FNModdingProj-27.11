// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Cosmetics/FortCosmeticOverlayMaterialTypes.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Variants/FortCosmeticLoadoutTagDrivenVariant.h"
#include "FortTypes.h"
#include "Sound/FortLayeredAudioComponent.h"
#include "AthenaGliderItemDefinition.generated.h"

class AFortPlayerParachute;
class UAnimInstance;
class UAnimSequence;
class UAthenaBackpackItemDefinition;
class UCurveFloat;
class UFortCameraMode;
class UFortPlayerGliderAnimSet;
class UMaterialInterface;
class UNiagaraSystem;
class UParticleSystem;
class USkeletalMesh;
class USoundBase;

UENUM(BlueprintType)
enum class EGliderTrailActivationMode : uint8
{
	/** Trail effect will be spawned but not activated. Useful if you want to activate a trail via Blueprints */
	None = 0,
	/** Trail effect will be activated as soon as the glider mesh becomes visible */
	AutoActivate = 1,
	/** Trail effect will be activated as soon as the glider is fully deployed according to its animation */
	FullyDeployed = 2,
};

UENUM(BlueprintType)
enum class EGliderTrailAttachmentMode : uint8
{
	/** Trail effect will be attached to the main glider mesh */
	GliderMesh = 0,
	/** Trail effect will be attached to the player pawn mesh */
	PlayerPawn = 1,
};

UENUM(BlueprintType)
enum class ELayeredAudioTriggerDirection : uint8
{
	AnyDirection = 0 UMETA(DisplayName="AnyDirection"),
	Forwards = 1 UMETA(DisplayName="Forwards"),
	Sideways = 2 UMETA(DisplayName="Sideways"),
	Backwards = 3 UMETA(DisplayName="Backwards"),
	Count = 4 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FFortGliderLayeredAudioOneshotGate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Asset")
	TSoftObjectPtr<USoundBase> SoundRef;

	UPROPERTY(EditDefaultsOnly, Category="Gate", meta=(ClampMax="0.900000", ClampMin="0.100000"))
	float GateValue;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	ELayeredAudioTriggerDir Direction;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	bool FadeWhenOutsideGate;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	float MinTimeSinceTrigger;

	UPROPERTY(EditDefaultsOnly, Category="Gate")
	float InterruptFadeTime;

};

USTRUCT(BlueprintType)
struct FFortGliderLayeredAudioFloatParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	ELayeredAudioInterpolationType InterpType;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="InterpType == ELayeredAudioInterpolationType::CustomCurve", EditConditionHides))
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	float AttackSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation", meta=(EditCondition="bEnabled"))
	float ReleaseSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Oneshots", meta=(EditCondition="bEnabled", TitleProperty="Sound"))
	TArray<FFortGliderLayeredAudioOneshotGate> Oneshots;

};

USTRUCT(BlueprintType)
struct FGliderBitsDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UAnimInstance> AnimBPClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition", meta=(AssetBundles="Equipped"))
	TArray<TSoftObjectPtr<UMaterialInterface>> OverrideMaterials;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition")
	FTransform RelativeTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GliderBitsDefinition")
	bool bApplyGliderMaterialOverrides;

};

USTRUCT(BlueprintType)
struct FGliderTrailParticleDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GliderTrailParticleDefinition", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;

	UPROPERTY(EditAnywhere, Category="GliderTrailParticleDefinition")
	FName EffectSocket;

	UPROPERTY(EditAnywhere, Category="GliderTrailParticleDefinition")
	FTransform Offset;

	UPROPERTY(EditAnywhere, Category="GliderTrailParticleDefinition")
	EGliderTrailActivationMode ActivationMode;

	UPROPERTY(EditAnywhere, Category="GliderTrailParticleDefinition")
	EGliderTrailAttachmentMode AttachmentMode;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaGliderItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(Category="Glider Mesh Transform", meta=(CallInEditor="true"))
	void CopyTransformFromGliderActor();
#endif

	UFUNCTION(BlueprintPure, Category="Athena")
	bool GetAttachNiagaraEffectToPlayerPawn() const;

	UFUNCTION(BlueprintPure)
	const TArray<FGliderBitsDefinition>& GetBits() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftClassPtr<UAnimInstance> GetOverrideAnimSetPtr() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftObjectPtr<USkeletalMesh> GetOverrideSkelMeshPtr() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSubclassOf<AFortPlayerParachute> GetParachutePrefabClass() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> GetPlayerAnimSetPtr() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftObjectPtr<UAnimSequence> GetPoseAdditive() const;

	UFUNCTION(BlueprintPure)
	const TArray<FGliderTrailParticleDefinition>& GetTrailEffectDefinitions() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	FName GetUserSkeletonParameterName() const;

	UFUNCTION(Category="Trail Effects", meta=(CallInEditor="true"))
	void MigrateGliderEffectDefinitions();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaGliderItemDefinition")
	EFortGliderType GliderType;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FrontendPreview")
	FVector CameraFramingBoundsCenterOffset;

private:
	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="ServerAthena,Equipped"))
	TSoftClassPtr<AFortPlayerParachute> ParachutePrefabClass;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	FTransform GliderMeshTransform;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UFortCameraMode> CameraClass;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortPlayerGliderAnimSet> PlayerAnimSet;

	UPROPERTY(EditDefaultsOnly, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UAnimSequence> PoseAdditive;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	FName AttachSocket;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	TArray<FGliderTrailParticleDefinition> TrailEffectDefinitions;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Visual")
	TArray<FFortCosmeticDependentSwapData> GlidingSwaps;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Visual|Niagara|DeployEffect")
	FName DeployEffectTagName;

	UPROPERTY(EditDefaultsOnly, Category="Visual|Niagara|DeployEffect")
	bool CleanUpDeployEffect;

	UPROPERTY(EditDefaultsOnly, Category="Visual|Niagara|SkeletonMesh")
	FName UserSkeletonParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> OpenSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> OpenFrontEndSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> CloseSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> ThrustLoopSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TMap<ELayeredAudioTriggerDirection, FFortGliderLayeredAudioFloatParam> ThrustSoundParams;

	UPROPERTY(EditDefaultsOnly, Category="Backbling Hiding")
	bool bShouldHideBackbling;

	UPROPERTY(EditDefaultsOnly, Category="Backbling Hiding")
	TArray<TSoftObjectPtr<UAthenaBackpackItemDefinition>> BackblingsToExcludeFromHiding;

	UPROPERTY(EditDefaultsOnly, Category="Backbling Hiding")
	FGameplayTagContainer BackblingSetsToExcludeFromHiding;

	UPROPERTY(EditDefaultsOnly, Category="Visual|Bits")
	TArray<FGliderBitsDefinition> Bits;

	UPROPERTY(EditAnywhere, Category="Visual")
	FFortCosmeticOverlayMaterialData OverlayMaterialData;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> TrailParticles;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> OwnerTrailParticles;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated")
	bool bActivateTrailsOnRotationalMovement;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated")
	FName TrailParamName;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> TrailEffect;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> TrailEffectNiagara;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> TrailEffect2;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Deprecated", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> TrailEffectNiagara2;

	UPROPERTY(EditDefaultsOnly, Category="Deprecated")
	bool bAttachNiagaraEffectToPlayerPawn;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Deprecated")
	bool bAutoActivate;

};

