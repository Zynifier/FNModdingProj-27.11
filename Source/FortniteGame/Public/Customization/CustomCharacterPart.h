// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Athena/AthenaMemoryBudgetInterface.h"
#include "CosmeticModifierProviderInterface.h"
#include "Cosmetics/FortCosmeticOverlayMaterialTypes.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortCustomPartTypeEnum.h"
#include "FortGender.h"
#include "SoundLibraryProviderInterface.h"
#include "CustomCharacterPart.generated.h"

class AActor;
class UAnimInstance;
class UAnimMontage;
class UCustomCharacterPart;
class UCustomCharacterPartData;
class UFortMontageLookupTable;
class UFortPlayerSkydiveAnimSet;
class UMaterialInterface;
class UNiagaraSystem;
class UParticleSystem;
class UPhysicsAsset;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundLibrary;
class UTexture;

UENUM()
enum class ECharacterPartAttachmentTargetType : uint8
{
	/** Root component for the part */
	RootComponent = 0,
	/**
	 * The mesh component from the associated player pawn for the right part type.
	 * Uses UCustomCharacterPartModifier.GetSkeletalMeshForAssociatedPlayerPawnPartType() to resolve
	 */
	SkeletalMeshForAssociatedPlayerPawnPartType = 1,
};

USTRUCT(BlueprintType)
struct FAppliedCharacterPartInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Export, Category="AppliedCharacterPartInfo", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> MeshComponent;

	UPROPERTY(BlueprintReadWrite, Category="AppliedCharacterPartInfo")
	TObjectPtr<UCustomCharacterPart> CharacterPart;

};

USTRUCT()
struct FAttachToComponentParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AttachToComponentParams")
	EAttachmentRule LocationRule;

	UPROPERTY(EditAnywhere, Category="AttachToComponentParams")
	EAttachmentRule RotationRule;

	UPROPERTY(EditAnywhere, Category="AttachToComponentParams")
	EAttachmentRule ScaleRule;

	UPROPERTY(EditAnywhere, Category="AttachToComponentParams")
	bool bWeldSimulatedBodies;

};

USTRUCT()
struct FCharacterPartAttachmentParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPartAttachmentParams")
	FName SocketName;

	UPROPERTY(EditAnywhere, Category="CharacterPartAttachmentParams")
	ECharacterPartAttachmentTargetType AttachmentTarget;

	UPROPERTY(EditAnywhere, Category="CharacterPartAttachmentParams")
	FAttachToComponentParams AttachmentRules;

};

USTRUCT()
struct FCustomPartMaterialOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	int32 MaterialOverrideIndex;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;

};

USTRUCT()
struct FCustomPartScalarParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	int32 MaterialIndexForScalarParameter;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	FName ScalarParameterNameForMaterial;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	float ScalarOverride;

};

USTRUCT(BlueprintType)
struct FCustomPartTextureParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	int32 MaterialIndexForTextureParameter;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	FName TextureParameterNameForMaterial;

private:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	TSoftObjectPtr<UTexture> TextureOverride;

};

USTRUCT()
struct FCustomPartVectorParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	int32 MaterialIndexForVectorParameter;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	FName VectorParameterNameForMaterial;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	FLinearColor VectorOverride;

};

UCLASS(MinimalAPI, BlueprintType)
class UCustomCharacterPart : public UPrimaryDataAsset, public IAthenaMemoryBudgetInterface, public ISoundLibraryProviderInterface, public ICosmeticModifierProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CharacterPart|Animation")
	TSubclassOf<UAnimInstance> GetAnimClass() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	EFortCustomPartType::Type GetCharacterPartType() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	TSoftObjectPtr<UParticleSystem> GetEffectCascade() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	TSoftObjectPtr<UNiagaraSystem> GetEffectNiagara() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Animation")
	TSubclassOf<UAnimInstance> GetFrontEndAnimClass() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	FName GetIdleFXSocketName() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Animation")
	TSubclassOf<UAnimInstance> GetMannequinAnimClass() const;

	UFUNCTION(BlueprintCallable, Category="CharacterPart|Art")
	TMap<int32, UMaterialInterface*> GetMaterialOverridesByIndex();

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	EFortCustomPartType::Type GetPartType() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Art")
	USkeletalMesh* GetSkeletalMesh() const;

	UFUNCTION(BlueprintPure, Category="CharacterPart|Animation")
	TSoftClassPtr<UAnimInstance> GetSoftAnimClass() const;

	UFUNCTION(BlueprintPure)
	bool ShouldAutoActivate() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="CharacterPart")
	TEnumAsByte<EFortCustomGender::Type> GenderPermitted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="CharacterPart")
	TEnumAsByte<EFortCustomBodyType::Type> BodyTypesPermitted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="CharacterPart", meta=(ForceRebuildProperty="AdditionalData"))
	TEnumAsByte<EFortCustomPartType::Type> CharacterPartType;

	UPROPERTY(EditAnywhere, Category="CharacterPart|BoneSetsToHide")
	FGameplayTagContainer BoneSetsToHide;

	UPROPERTY(EditAnywhere, Category="CharacterPart|BoneSetsToHide")
	bool bShouldHideBonesForThisPart;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CharacterPart", meta=(AllowedClasses="/Script/FortniteGame.CustomCharacterPartModifier"))
	TSoftClassPtr<AActor> PartModifierBlueprint;

	UPROPERTY(VisibleAnywhere, Instanced, Category="CharacterPart")
	TObjectPtr<UCustomCharacterPartData> AdditionalData;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation")
	TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation")
	TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation")
	TSoftObjectPtr<UFortPlayerSkydiveAnimSet> SkydiveAnimSet;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation")
	float FrontEndBackPreviewRotationOffset;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="CharacterPart|Art")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="CharacterPart|Art")
	TArray<TSoftObjectPtr<USkeletalMesh>> MasterSkeletalMeshes;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="CharacterPart|Art")
	bool bSinglePieceMesh;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	bool bSupportsColorSwatches;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Animation")
	bool bAllowStaticRenderPath;

	UPROPERTY(EditAnywhere, Category="Collision")
	TSoftObjectPtr<UPhysicsAsset> PhysicsOverrideAsset;

private:
	UPROPERTY(EditAnywhere, Category="CharacterPart")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="CharacterPart", meta=(Categories="Cosmetics"))
	FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="CharacterPart")
	bool bGameplayRelevantCosmeticPart;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, AdvancedDisplay, Category="CharacterPart")
	bool bContributesToPartBudget;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	bool bAttachToSocket;

	UPROPERTY(EditAnywhere, Category="CharacterPart")
	bool bIgnorePart;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	TArray<FCustomPartMaterialOverrideData> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	TArray<FCustomPartTextureParameter> TextureParameters;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	TArray<FCustomPartScalarParameter> ScalarParameters;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	TArray<FCustomPartVectorParameter> VectorParameters;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	FFortCosmeticOverlayMaterialData OverlayMaterialData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="CharacterPart|Art")
	TArray<int32> IgnoredMaterialOverrideIndices;
#endif

	UPROPERTY(EditAnywhere, Category="CharacterPart|SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> SoundLibraries;

	UPROPERTY()
	int32 MaterialOverrideFlags;

	UPROPERTY()
	int32 IgnoredMaterialOverrideFlags;

	UPROPERTY(EditDefaultsOnly, Category="CharacterPart|Effect")
	TSoftObjectPtr<UParticleSystem> IdleEffect;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Effect")
	TSoftObjectPtr<UNiagaraSystem> IdleEffectNiagara;

	UPROPERTY(EditDefaultsOnly, Category="CharacterPart|Effect")
	FName IdleFXSocketName;

	UPROPERTY(EditAnywhere, Category="CustomCharacterPart", meta=(InlineEditConditionToggle="IdleFXNativeCustomAttachmentParams"))
	bool bUseIdleFXNativeCustomAttachmentParams;

	UPROPERTY(EditAnywhere, Category="CharacterPart|Effect", meta=(EditCondition="bUseIdleFXNativeCustomAttachmentParams"))
	FCharacterPartAttachmentParams IdleFXNativeCustomAttachmentParams;

	UPROPERTY(EditDefaultsOnly, Category="CharacterPart|Effect")
	bool bAutoActivate;

};

