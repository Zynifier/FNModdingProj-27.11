// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Stats/FortStatManagerTag.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "GameDataCosmetics.generated.h"

class AActor;
class AFortBodyPartOverridePreviewActor;
class AFortCharmPreviewActor;
class AFortEmotePreviewActor;
class AFortItemPreviewActor;
class AFortItemWrapPreviewActor;
class AFortLoadingScreenPreviewActor;
class AFortMusicPackPreviewActor;
class AFortPickaxePreviewActor;
class AFortSkyDiveContrailPreviewActor;
class AFortSprayPreviewActor;
class AFortWeaponCharmPreviewActor;
class UAnimMontage;
class UAthenaBackpackItemDefinition;
class UAthenaBattleBusItemDefinition;
class UAthenaDanceItemDefinition;
class UAthenaGliderItemDefinition;
class UAthenaMusicPackItemDefinition;
class UAthenaPickaxeItemDefinition;
class UAthenaSkyDiveContrailItemDefinition;
class UCurveFloat;
class UCustomCharacterPart;
class UDataTable;
class UFortAIPawnCustomizationDefinition;
class UFortCharmsMappingData;
class UFortCosmeticItemFilterTable;
class UFortCosmeticItemMarkupTable;
class UFortCosmeticStatObject;
class UFortGameplayAbility;
class UFortHomebaseBannerColorMap;
class UFortItemDefinition;
class UFortMetaTagToPreviewActorMapping;
class UFrontendAnimInstance;
class UObject;
class UPhysicsAsset;
class USkeletalMesh;
class UTexture2D;

UENUM()
enum class ECosmeticBudgetingMode : uint8
{
	Direct = 0,
	IndirectOrNone = 1,
};

USTRUCT(BlueprintType)
struct FEmoteActivationTrigger
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EmoteActivationTrigger")
	FGameplayTagQuery EmoteTagQuery;

	UPROPERTY(EditAnywhere, Category="EmoteActivationTrigger")
	FGameplayTagQuery PlayerTagQuery;

	UPROPERTY(EditAnywhere, Category="EmoteActivationTrigger")
	FGameplayTagContainer TagsToApply;

	UPROPERTY(EditAnywhere, Category="EmoteActivationTrigger")
	float Duration;

};

USTRUCT(BlueprintType)
struct FFallbackAIPawnCustomizationMapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FallbackAIPawnCustomizationMapper")
	FGameplayTag RequiredTag;

	UPROPERTY(EditAnywhere, Category="FallbackAIPawnCustomizationMapper")
	TSoftObjectPtr<UFortAIPawnCustomizationDefinition> CustomizationFallback;

};

USTRUCT(BlueprintType)
struct FFallbackCharacterPartsMapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterCustomization")
	FGameplayTag RequiredTag;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterParts;

};

UCLASS(MinimalAPI)
class UGameDataCosmetics : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void CreateBannerAssets();

	UFUNCTION(BlueprintPure)
	const TArray<FName>& GetHideElementParameterNames() const;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics")
	TSoftObjectPtr<UAthenaPickaxeItemDefinition> FallbackPickaxe;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics")
	TSoftObjectPtr<USkeletalMesh> FallbackPickaxeMesh;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics")
	TSoftObjectPtr<USkeletalMesh> FallbackDualWieldPickaxeMesh;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics")
	TSoftObjectPtr<UAthenaDanceItemDefinition> FallbackDance;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics", meta=(AssetBundles="Client"))
	TArray<TSoftObjectPtr<UFortItemDefinition>> ShuffleTileItemDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaBackpackItemDefinition> STWHeroBackpackItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaBackpackItemDefinition> STWHeroNoDefaultBackpackItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaBattleBusItemDefinition> DefaultBattleBusSkin;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaGliderItemDefinition> DefaultGliderSkin;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaSkyDiveContrailItemDefinition> DefaultContrailEffect;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TObjectPtr<UAthenaMusicPackItemDefinition> DefaultMusicPack;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics", meta=(AllowedTypes="AthenaCharacter"))
	TArray<FPrimaryAssetId> ValidMaleSkinsForAnonymousMode;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics", meta=(AllowedTypes="AthenaCharacter"))
	TArray<FPrimaryAssetId> ValidFemaleSkinsForAnonymousMode;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics", meta=(AllowedTypes="AthenaBackpack"))
	TArray<FPrimaryAssetId> ValidBackPacksForAnonymousMode;

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UFortCosmeticItemFilterTable> FilterTagTable;

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UFortCosmeticItemMarkupTable> CosmeticMarkupTable;

	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> CosmeticPreviewActionList;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> CharacterPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortEmotePreviewActor> EmotePreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> EmotePreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortItemWrapPreviewActor> ItemWrapPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> ItemWrapPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortLoadingScreenPreviewActor> LoadingScreenPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> LoadingScreenPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortSprayPreviewActor> SprayPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> SprayPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortMusicPackPreviewActor> MusicPackPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> MusicPackPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortSkyDiveContrailPreviewActor> SkyDiveContrailPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> SkyDiveContrailPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> SkyDiveContrailAnimation_Male;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> SkyDiveContrailAnimation_Female;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> PickaxePreviewMontage_Idle2H;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> PickaxePreviewMontage_Swing2H;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> PickaxePreviewMontage_IdleDualWield;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<UAnimMontage> PickaxePreviewMontage_SwingDualWield;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> GliderPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortBodyPartOverridePreviewActor> BodyPartOverridePreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> BodyPartPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortCharmPreviewActor> CharmPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> CharmPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortWeaponCharmPreviewActor> WeaponCharmPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> WeaponCharmPreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortPickaxePreviewActor> PickaxeCosmeticPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> PickaxePreviewCameraActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> BannerItemPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> CurrencyItemPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> BattlePassItemPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> ToyItemPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> DefaultPreviewActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftClassPtr<UFrontendAnimInstance> DefaultPreviewPawnAnimInstanceClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TObjectPtr<UFortMetaTagToPreviewActorMapping> MetaTagToPreviewActorAsset;

	UPROPERTY(EditAnywhere, Category="Preview")
	float ItemPreviewLODStreamingTimeout;

	UPROPERTY(EditAnywhere, Category="Visual")
	TMap<EAthenaCustomizationCategory, TSoftClassPtr<AActor>> CosmeticPreviewActionMap;

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UFortCharmsMappingData> CharmConfigAsset;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftObjectPtr<UTexture2D> NoneTexture;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftObjectPtr<UTexture2D> DeniedCosmeticThumbnail;

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UFortItemDefinition> PlaceholderItemToShowForDeniedCosmetics;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics", meta=(AllowedTypes="AthenaCharacter"))
	TArray<FPrimaryAssetId> RandomCharacters;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UCurveFloat> CameraPositionTransitionCurve;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraPositionTransitionDuration;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraPositionTargetMaxLerpDistance;

	UPROPERTY(EditAnywhere, Category="Camera")
	float MinPanelSizeForFraming;

	UPROPERTY(EditAnywhere, Category="HarvestingTool")
	FFortHarvestingToolMontageOverrides HarvestingToolMontageOverrides;

	UPROPERTY()
	TArray<uint8> BakedThumbnailData;

	UPROPERTY(EditAnywhere, Category="Emote")
	TArray<FEmoteActivationTrigger> EmoteActivationTriggers;

	UPROPERTY(EditAnywhere, Category="GameDataCosmetics")
	int32 BaseCharacterIndex;

	UPROPERTY(EditAnywhere, Category="Character Part Default Physics Assets", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UPhysicsAsset> HeadDefaultPhysicsAsset;

	UPROPERTY(EditAnywhere, Category="Character Part Default Physics Assets", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UPhysicsAsset> FaceDefaultPhysicsAsset;

	UPROPERTY(EditAnywhere, Category="Stats")
	TArray<TSoftClassPtr<UFortCosmeticStatObject>> CosmeticStatObjects;

	UPROPERTY(EditDefaultsOnly, Category="Reactives")
	TMap<FFortStatManagerTag, float> DefaultStatDelays;

private:
	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortGameplayAbility> EmoteGameplayAbility;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortGameplayAbility> TransformEmoteGameplayAbility;

	UPROPERTY(EditAnywhere, Category="Spray", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortGameplayAbility> SprayGameplayAbility;

	UPROPERTY(EditAnywhere, Category="Emote", meta=(AssetBundles="Client,Server"))
	FGameplayTagQuery TransformEmoteTagQuery;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCustomCharacterPart> DefaultBackpackCharacterPart;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization", meta=(AssetBundles="Client,Server"))
	TArray<TSoftObjectPtr<UCustomCharacterPart>> DefaultCharacterParts;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization")
	TArray<FFallbackCharacterPartsMapper> FallbackCharacterParts;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization")
	TArray<FFallbackAIPawnCustomizationMapper> FallbackCustomizations;

	UPROPERTY(EditDefaultsOnly, Category="Banners", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> BannerIconCategoryData;

	UPROPERTY(EditDefaultsOnly, Category="Banners", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> BannerColorData;

	UPROPERTY(EditDefaultsOnly, Category="Banners", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> BannerColorCategoryData;

	UPROPERTY(EditDefaultsOnly, Category="Banners", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortHomebaseBannerColorMap> BannerColorMap;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmetics")
	TArray<FName> HideElementParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Budgeting")
	ECosmeticBudgetingMode DefaultBudgetingMode;

	UPROPERTY(EditDefaultsOnly, Category="Budgeting")
	TMap<UClass*, ECosmeticBudgetingMode> ClassBudgetingModeOverrides;

};

