// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/Variants/FortAppliedSwapItemAndVariantStateEnum.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortCosmeticVariantTypes.generated.h"

class UAnimInstance;
class UAnimMontage;
class UAthenaCosmeticItemDefinition;
class UCustomCharacterPart;
class UCustomDynamicColorSwatch;
class UFXSystemAsset;
class UFortAccountItemDefinition;
class UFortItemDefinition;
class UMaterialInterface;
class USkeletalMesh;
class USoundBase;
class USoundEffectSourcePresetChain;
class USoundLibrary;
class UTexture2D;
class UTexture;

UENUM()
enum class EAnimInstanceClassSwapType : uint8
{
	// No anim instance swap

	None = 0,
	// Swap if AnimInstanceClassToSwap matches AnimInstanceClass used by the mesh component being modified

	SwapOnMatch = 1,
};

UENUM(BlueprintType)
enum class EItemWrapMaterialType : uint8
{
	WeaponWrap = 0,
	VehicleWrap_Opaque = 1,
	VehicleWrap_Masked = 2,
	Character = 3,
};

UENUM()
enum class ELoadoutVariantInsertType : uint8
{
	StartOfArray = 0,
	EndOfArray = 1,
};

USTRUCT()
struct FApplyWrapVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(GetOptions="FortniteGame.AthenaCosmeticItemDefinition.GetAllPossibleNativeMeshComponentNames"))
	TArray<FName> ComponentNameAllowList;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames"))
	int32 WrapSectionMask;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames", GetOptions="FortniteGame.AthenaCosmeticItemDefinition.GetAllPossibleNativeMeshComponentNames"))
	TMap<FName, int32> CustomSectionMaskByMeshName;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TSet<TSoftObjectPtr<USkeletalMesh>> AllowedMeshes;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FString DefaultSelectedItem;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	EItemWrapMaterialType WrapMaterialType;

};

USTRUCT()
struct FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bStartUnlocked;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bIsDefault;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bHideIfNotOwned;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag CustomizationVariantTag;

	UPROPERTY(EditAnywhere, Category="Display Data")
	FText VariantName;

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UTexture2D> PreviewImage;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int32 ShotGridId;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<int32> ShotGridIds;
#endif

private:
	UPROPERTY(EditAnywhere, Category="Display Data", meta=(MultiLine="true"))
	FText UnlockRequirements;

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UFortAccountItemDefinition> UnlockingItemDef;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FGameplayTagContainer VariantGameplayTags;

};

USTRUCT()
struct FCosmeticMetaTagContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CosmeticMetaTagContainer")
	FGameplayTagContainer MetaTagsToApply;

	UPROPERTY(EditAnywhere, Category="CosmeticMetaTagContainer")
	FGameplayTagContainer MetaTagsToRemove;

};

USTRUCT()
struct FApplyWrapVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(ShowOnlyInnerProperties))
	FApplyWrapVariant InnerDef;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FGameplayTagContainer FilterOutItemsWithTags;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bAllowClear;

};

USTRUCT()
struct FCosmeticMetaTagStack
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer CurrentState;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDisplayManagerVariantData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticItemDef;

	UPROPERTY()
	TArray<FMcpVariantChannelInfo> CosmeticVariantChannels;

};

USTRUCT()
struct FDynamicVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

};

USTRUCT()
struct FEmoteMontageSwap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EmoteMontageSwap")
	TSoftObjectPtr<UAnimMontage> ToSwapFrom;

	UPROPERTY(EditAnywhere, Category="EmoteMontageSwap")
	TSoftObjectPtr<UAnimMontage> ToSwapTo;

};

USTRUCT()
struct FEmoteMontageVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="ToSwapFrom"))
	TArray<FEmoteMontageSwap> MontageSwaps;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT()
struct FFoleySoundVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FoleySoundVariant")
	TArray<TObjectPtr<USoundLibrary>> LibrariesToAdd;

	UPROPERTY(EditAnywhere, Category="FoleySoundVariant")
	TArray<TObjectPtr<USoundLibrary>> LibrariesToRemove;

};

USTRUCT(BlueprintType)
struct FFortSwapItemAndVariantData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSwapItemAndVariantData")
	TObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSwapItemAndVariantData", meta=(TitleProperty="VariantChannelTag"))
	TArray<FMcpVariantChannelInfo> ChannelInfoList;

};

USTRUCT()
struct FFortAppliedSwapItemAndVariantData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid SwapId;

	UPROPERTY()
	EFortAppliedSwapItemAndVariantState SwapState;

	UPROPERTY()
	TArray<FFortSwapItemAndVariantData> SwapData;

};

USTRUCT()
struct FItemTextureVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<TSoftObjectPtr<UFXSystemAsset>> ParticleSystemsToAlter;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FName ParamName;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FString DefaultSelectedItem;

};

USTRUCT()
struct FItemTextureVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(ShowOnlyInnerProperties))
	FItemTextureVariant InnerDef;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FGameplayTagContainer FilterOutItemsWithTags;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bWantsSprays;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bWantsEmoji;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bAllowClear;

};

USTRUCT()
struct FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Material Params")
	FName ParamName;

};

USTRUCT()
struct FMaterialFloatVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Material Params")
	float Value;

};

USTRUCT()
struct FMaterialTextureVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Material Params", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UTexture> Value;

};

USTRUCT()
struct FMaterialVectorVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Material Params")
	FLinearColor Value;

};

USTRUCT()
struct FMaterialParamterDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MaterialParamterDef")
	TSoftObjectPtr<UMaterialInterface> MaterialToAlter;

	UPROPERTY(EditAnywhere, Category="MaterialParamterDef")
	FName CascadeMaterialName;

	UPROPERTY(EditAnywhere, Category="MaterialParamterDef")
	TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere, Category="MaterialParamterDef")
	TArray<FMaterialTextureVariant> TextureParams;

	UPROPERTY(EditAnywhere, Category="MaterialParamterDef")
	TArray<FMaterialFloatVariant> FloatParams;

};

USTRUCT()
struct FMaterialVariants
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MaterialVariants")
	TSoftObjectPtr<UMaterialInterface> MaterialToSwap;

	UPROPERTY(EditAnywhere, Category="MaterialVariants")
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere, Category="MaterialVariants", meta=(DisplayName="Particle System Parameter Name"))
	FName CascadeMaterialName;

	UPROPERTY(EditAnywhere, Category="MaterialVariants")
	int32 MaterialOverrideIndex;

	UPROPERTY(EditAnywhere, Category="MaterialVariants")
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;

};

USTRUCT()
struct FMeshVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MeshVariant")
	TSoftObjectPtr<USkeletalMesh> MeshToSwap;

	UPROPERTY(EditAnywhere, Category="MeshVariant")
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere, Category="MeshVariant")
	TSoftObjectPtr<USkeletalMesh> OverrideMesh;

	UPROPERTY(EditAnywhere, Category="MeshVariant")
	EAnimInstanceClassSwapType AnimInstanceClassSwapType;

	UPROPERTY(EditAnywhere, Category="MeshVariant", meta=(EditCondition="AnimInstanceClassSwapType != EAnimInstanceClassSwapType::None"))
	TSoftClassPtr<UAnimInstance> AnimInstanceClassToSwap;

	UPROPERTY(EditAnywhere, Category="MeshVariant", meta=(EditCondition="AnimInstanceClassSwapType != EAnimInstanceClassSwapType::None"))
	TSoftClassPtr<UAnimInstance> OverrideAnimInstanceClass;

};

USTRUCT()
struct FVectorParamVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Material Params")
	FVector Value;

};

USTRUCT()
struct FParticleParamterVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ParticleParamterVariant")
	TSoftObjectPtr<UFXSystemAsset> ParticleSystemToAlter;

	UPROPERTY(EditAnywhere, Category="ParticleParamterVariant")
	TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere, Category="ParticleParamterVariant")
	TArray<FVectorParamVariant> VectorParams;

	UPROPERTY(EditAnywhere, Category="ParticleParamterVariant")
	TArray<FMaterialFloatVariant> FloatParams;

	UPROPERTY(EditAnywhere, Category="ParticleParamterVariant")
	TArray<FMaterialTextureVariant> TextureParams;

};

USTRUCT()
struct FParticleVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ParticleVariant")
	TSoftObjectPtr<UFXSystemAsset> ParticleSystemToAlter;

	UPROPERTY(EditAnywhere, Category="ParticleVariant")
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere, Category="ParticleVariant")
	TSoftObjectPtr<UFXSystemAsset> OverrideParticleSystem;

	UPROPERTY(EditAnywhere, Category="ParticleVariant")
	bool bResetParameterOverridesOnSwap;

};

USTRUCT()
struct FScriptedActionVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ScriptedActionVariant", meta=(Categories="Cosmetics.Variant.Actions"))
	FGameplayTag ActionTag;

};

USTRUCT()
struct FSocketTransformVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SocketTransformVariant")
	FName SourceSocketName;

	UPROPERTY(EditAnywhere, Category="SocketTransformVariant")
	FName OverridSocketName;

	UPROPERTY(EditAnywhere, Category="SocketTransformVariant")
	TSoftObjectPtr<USkeletalMesh> SourceObjectToModify;

};

USTRUCT()
struct FSoundVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoundVariant")
	TSoftObjectPtr<USoundBase> SoundToSwap;

	UPROPERTY(EditAnywhere, Category="SoundVariant")
	FName ComponentToOverride;

	UPROPERTY(EditAnywhere, Category="SoundVariant")
	TSoftObjectPtr<USoundBase> OverrideSound;

};

USTRUCT()
struct FVariantParticleSystemInitializerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	FName ParticleComponentName;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UFXSystemAsset> ParticleSystem;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	TSoftObjectPtr<USkeletalMesh> MeshToBindTO;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	FName AttachSocketName;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	EAttachmentRule LocationRule;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	EAttachmentRule RotationRule;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	EAttachmentRule ScaleRule;

	UPROPERTY(EditAnywhere, Category="VariantParticleSystemInitializerData")
	bool bWeldSimulatedBodies;

};

USTRUCT()
struct FPartVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantParts;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FVariantParticleSystemInitializerData> InitalParticleSystemData;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleParamterVariant> VariantParticleParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSoundVariant> VariantSounds;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(DisplayName="Variant Sound Libraries"))
	TArray<FFoleySoundVariant> VariantFoley;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSocketTransformVariant> SocketTransforms;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FScriptedActionVariant> VariantActions;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMeshVariant> VariantMeshes;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(BaseStruct="/Script/CosmeticsFrameworkItems.CosmeticPropertyBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> CosmeticProperties;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT()
struct FLoadoutVariantDef : public FPartVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> LoadoutItem;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	ELoadoutVariantInsertType LocationToInsert;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bItemExpectedInLoadout;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bRequireItemToBeCurrent;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	bool bIgnoreRequireItemToBeCurrentInFrontEnd;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FEmoteMontageVariantDef> VariantEmoteMontages;

};

USTRUCT()
struct FMaterialVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSoundVariant> VariantSounds;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(DisplayName="Variant Sound Libraries"))
	TArray<FFoleySoundVariant> VariantFoley;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(BaseStruct="/Script/CosmeticsFrameworkItems.CosmeticPropertyBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> CosmeticProperties;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT()
struct FMcpVariantReader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="McpVariantReader")
	FString Channel;

	UPROPERTY(EditAnywhere, Category="McpVariantReader")
	FString Active;

	UPROPERTY(EditAnywhere, Category="McpVariantReader")
	TArray<FString> Owned;

};

USTRUCT()
struct FMcpVariantWriter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FGameplayTag VariantChannel;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FGameplayTag ActiveVariant;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FString CustomActiveVariant;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FGameplayTagContainer UnlockedVariants;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FString CustomUnlockedVariants;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FString ColorSwatch;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	int32 AntiConflictChannel;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	FString AntiConflictRules;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	float AntiConflictMinimumDistance;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	float AntiConflictMinimumContrast;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	float AntiConflictMinimumHueShift;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	float AntiConflictMinimumSaturationShift;

	UPROPERTY(EditAnywhere, Category="McpVariantWriter")
	TArray<FString> UnlockRequirements;

};

USTRUCT()
struct FMeshVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMeshVariant> VariantMeshes;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FVariantParticleSystemInitializerData> InitialParticleSystemData;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleParamterVariant> VariantParticleParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSocketTransformVariant> SocketTransforms;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSoundVariant> VariantSounds;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(DisplayName="Variant Sound Libraries"))
	TArray<FFoleySoundVariant> VariantFoley;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FScriptedActionVariant> VariantActions;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(BaseStruct="/Script/CosmeticsFrameworkItems.CosmeticPropertyBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> CosmeticProperties;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT(meta=(DisplayName="StaticParticleVariant"))
struct FParticleVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FMaterialParamterDef> VariantMaterialParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FVariantParticleSystemInitializerData> InitialParticleSystemData;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FParticleParamterVariant> VariantParticleParams;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSoundVariant> VariantSounds;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(BaseStruct="/Script/CosmeticsFrameworkItems.CosmeticPropertyBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> CosmeticProperties;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT()
struct FRichColorVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Color Variant")
	FLinearColor DefaultStartingColor;

	UPROPERTY(EditAnywhere, Category="Color Variant")
	TSoftObjectPtr<UCustomDynamicColorSwatch> ColorSwatchForChoices;

	UPROPERTY(VisibleAnywhere, Category="Color Variant")
	bool bVariantPickerShouldShowHSV;

	UPROPERTY(EditAnywhere, Category="Color Variant")
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;

	UPROPERTY(EditAnywhere, Category="Color Variant")
	TArray<TSoftObjectPtr<UFXSystemAsset>> ParticlesToAlter;

	UPROPERTY(EditAnywhere, Category="Color Variant")
	FName ColorParamName;

};

USTRUCT()
struct FRichColorVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(ShowOnlyInnerProperties))
	FRichColorVariant RichColorVar;

};

USTRUCT()
struct FScriptedActionVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FScriptedActionVariant> VariantActions;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

USTRUCT()
struct FSocketVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FSocketTransformVariant> SocketTransforms;

};

USTRUCT()
struct FSoundEffectVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoundEffectVariant")
	TArray<TSoftObjectPtr<USoundBase>> SoundsToModify;

	UPROPERTY(EditAnywhere, Category="SoundEffectVariant")
	TArray<FName> ComponentsToApplyTo;

	UPROPERTY(EditAnywhere, Category="SoundEffectVariant")
	TSoftObjectPtr<USoundEffectSourcePresetChain> EffectChain;

};

UCLASS(Abstract, EditInlineNew)
class UVariantTypeBase : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UVariantScriptedAction : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FScriptedActionVariant> VariantActions;

};

UCLASS()
class UVariantTypeCharacterParts : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantParts;

};

UCLASS()
class UVariantTypeEmoteMontage : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FEmoteMontageVariantDef> VariantEmotes;

};

UCLASS()
class UVariantTypeInitialParticleSystemData : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="ParticleSystem"))
	TArray<FVariantParticleSystemInitializerData> VariantInitialParticleSystemData;

};

UCLASS()
class UVariantTypeItemTexture : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="MaterialToAlter"))
	FItemTextureVariant VariantItemTextures;

};

UCLASS()
class UVariantTypeMaterialParams : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="MaterialToAlter"))
	TArray<FMaterialParamterDef> VariantMaterialParams;

};

UCLASS()
class UVariantTypeMaterials : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="MaterialToSwap"))
	TArray<FMaterialVariants> VariantMaterials;

};

UCLASS()
class UVariantTypeMeshes : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="MeshToSwap"))
	TArray<FMeshVariant> VariantMeshes;

};

UCLASS()
class UVariantTypeParticleParams : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="ParticleSystemToAlter"))
	TArray<FParticleParamterVariant> VariantParticleParams;

};

UCLASS()
class UVariantTypeParticles : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="ParticleSystemToAlter"))
	TArray<FParticleVariant> VariantParticles;

};

UCLASS()
class UVariantTypeRichColor : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(ShowOnlyInnerProperties))
	FRichColorVariant RichColorDef;

};

UCLASS()
class UVariantTypeSocketTransforms : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="SourceSocketName"))
	TArray<FSocketTransformVariant> VariantSocketTransforms;

};

UCLASS()
class UVariantTypeSounds : public UVariantTypeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="SoundToSwap"))
	TArray<FSoundVariant> VariantSounds;

};

