// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Math/MathFwd.h"
#include "UObject/SoftObjectPath.h"
#include "CosmeticCustomizableItemDefinition.h"
#include "CosmeticLoadoutItemDefinition.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Gating/CosmeticItemGatingInterface.h"
#include "Cosmetics/Variants/FortCosmeticVarianceFlowTypes.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Items/FortAccountItemDefinition.h"
#include "Stats/FortStatManagerTag.h"
#include "AthenaCosmeticItemDefinition.generated.h"

class AActor;
class AFortCosmeticReactivePreview;
class AFortItemPreviewActor;
class AFortPlayerController;
class AFortPlayerPawn;
class UAnimMontage;
class UAthenaCharacterItemDefinition;
class UAthenaCosmeticItemDefinition;
class UFXSystemAsset;
class UFortAccountItemDefinition;
class UFortCosmeticItemAdditionalData;
class UFortCosmeticVariant;
class UFortItem;
class UFortMontageItemDefinitionBase;
class UFortVariantPreviewGenerator;
class UMaterialInterface;
class UObject;
class UPrimitiveComponent;
class USoundLibrary;
class UTexture2D;
enum class EVariantUnlockType : uint8;

UENUM(BlueprintType)
enum class EVariantUnlockType : uint8
{
	UnlockAll = 0,
	ExclusiveChoice = 1,
};

USTRUCT()
struct FAthenaCosmeticItemDefinitionWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaCosmeticItemDefinition> ItemDef;

};

USTRUCT()
struct FAthenaCosmeticMaterialOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Override")
	FName ComponentName;

	UPROPERTY(EditAnywhere, Category="Override")
	int32 MaterialOverrideIndex;

	UPROPERTY(EditAnywhere, Category="Override", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;

};

USTRUCT()
struct FCosmeticContentOnDemandTelemetryData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 NumDynamicInstallBundles;

	UPROPERTY(Transient)
	bool bDynamicInstallBundlesError;

	UPROPERTY(Transient)
	bool bDynamicInstallCancelled;

	UPROPERTY(Transient)
	double InstallTime;

	UPROPERTY(Transient)
	int32 RetryCount;

	UPROPERTY(Transient)
	FString LastDynamicInstallBundleError;

};

USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	FFortStatManagerTag StatTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	int32 StatValue;

};

USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPreview
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview", meta=(MultiLine="true"))
	FText UnlockCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	TArray<FFortCosmeticAdaptiveStatPair> StatValues;

};

USTRUCT(BlueprintType)
struct FFortCosmeticVariantPreviewElement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	TObjectPtr<UAthenaCosmeticItemDefinition> Item;

};

USTRUCT(BlueprintType)
struct FFortCosmeticVariantPreview
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview", meta=(MultiLine="true"))
	FText UnlockCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	float PreviewTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Preview")
	TArray<FFortCosmeticVariantPreviewElement> AdditionalItems;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaCosmeticItemDefinition : public UFortAccountItemDefinition, public ICosmeticLoadoutItemDefinition, public ICosmeticCustomizableItemDefinition, public ICosmeticItemGatingInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Cosmetics", meta=(AutoCreateRefTerm="Params"))
	FORTNITEGAME_API virtual void ApplyVariants(AActor* InActor, const FFortAthenaLoadout& Loadout, const FApplyVariantsAdditionalParams& Params) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Cosmetics", meta=(AutoCreateRefTerm="Params"))
	FORTNITEGAME_API virtual void ApplyVariantsToComponent(UPrimitiveComponent* InComponent, const FFortAthenaLoadout& Loadout, const FApplyVariantsAdditionalParams& Params) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Cosmetics", meta=(DisplayName="Gather Variant Assets (Deprecated)"))
	FORTNITEGAME_API virtual void GatherVariantAssets(AActor* InActor, const FFortAthenaLoadout& Loadout, TArray<FSoftObjectPath>& VariantAssetsNeeded, AFortPlayerPawn* InPlayerPawn) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API const FGameplayTagContainer& GetAdaptivePlayerStatsList() const;

	UFUNCTION()
	FORTNITEGAME_API static TArray<FString> GetAllPossibleNativeMeshComponentNames();

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API const UFortCosmeticItemAdditionalData* GetDataOfType(TSubclassOf<UFortCosmeticItemAdditionalData> Class) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API void GetDefaultVariantChannels(TArray<FMcpVariantChannelInfo>& OutDefaultVariantData) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API const TArray<FFortCosmeticAdaptiveStatPreview>& GetItemAdaptiveStatPreviews() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API const TArray<FFortCosmeticVariantPreview>& GetItemVariantPreviews() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API TArray<FFortCosmeticVariantPreview> GetOrGenerateItemVariantPreviews(const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure, Category="Frontend Preview")
	FORTNITEGAME_API FRotator GetPreviewPawnRotationOffset() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API UFortCosmeticVariant* GetVariantChannel(FGameplayTag InVariantChannelTag) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API EVariantUnlockType GetVariantUnlockType() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API bool HasChannelOfType(TSubclassOf<UFortCosmeticVariant> Class) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API bool HasModifiableVariants(const UFortItem* InItem = nullptr) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API bool HasVariants() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API virtual bool IsEnabledInSTW() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API bool IsOwnedByCampaignHero() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics", meta=(DefaultToSelf="InWorldContext"))
	FORTNITEGAME_API bool IsVariantSelectionDisabled(const UObject* InWorldContext = nullptr) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Custom Character")
	FORTNITEGAME_API virtual void UpdateLockedFloatSliderVariant(const AFortPlayerController* FortPC, FGameplayTag ChannelTag) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	uint8 bIsShuffleTile : 1;

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	uint8 bIsOwnedByCampaignHero : 1;

	UPROPERTY(VisibleDefaultsOnly, Transient, Category="Variants")
	uint8 bHasMoreThanOneCharacterPartVariant : 1;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bHideIfNotOwned : 1;

	UPROPERTY()
	FString DynamicInstallBundleName;

	UPROPERTY(Transient)
	uint8 bInitializedConfiguredDynamicInstallBundles : 1;

	UPROPERTY(Transient)
	uint8 bDynamicInstallBundlesError : 1;

	UPROPERTY(Transient)
	uint8 bDynamicInstallBundlesCancelled : 1;

	UPROPERTY(Transient)
	uint8 bDynamicInstallBundlesComplete : 1;

	UPROPERTY(Transient)
	double DynamicInstallBundlesUpdateStartTime;

	UPROPERTY(Transient)
	double DynamicInstallBundlesUpdateTotalTime;

	UPROPERTY(Transient)
	uint32 DynamicInstallBundleRequestRefCount;

	UPROPERTY(Transient)
	int32 DynamicInstallBundleRequestRetryCount;

	UPROPERTY(EditAnywhere, Category="Variants")
	EVariantUnlockType VariantUnlockType;

	UPROPERTY(EditDefaultsOnly, Category="Deprecated")
	FRotator PreviewPawnRotationOffset;

	UPROPERTY(EditAnywhere, Category="SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> CosmeticSoundLibraries;

	UPROPERTY(EditAnywhere, Category="Display", meta=(Categories="Cosmetics"))
	FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere, Category="Display", meta=(Categories="Cosmetics"))
	FGameplayTagContainer MetaTags;

	UPROPERTY(EditAnywhere, Category="Display", meta=(Categories="Cosmetics.Channel"))
	TArray<FGameplayTag> VariantChannelsToNeverSendToMCP;

	UPROPERTY(EditAnywhere, Category="Display")
	TMap<FCosmeticVariantInfo, TSoftClassPtr<AFortCosmeticReactivePreview>> ReactivePreviewDrivers;

	UPROPERTY(EditAnywhere, Category="Visual|Overrides", meta=(AssetBundles="Equipped"))
	TArray<FAthenaCosmeticMaterialOverride> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category="Visual|Overrides", meta=(Categories="StatManager"))
	FGameplayTagContainer ObservedPlayerStats;

	UPROPERTY(EditAnywhere, Category="Visual|Overrides")
	TArray<TObjectPtr<UFortMontageItemDefinitionBase>> BuiltInEmotes;

	UPROPERTY(EditAnywhere, Instanced, Category="Variants", meta=(TitleProperty="VariantChannelName"))
	TArray<TObjectPtr<UFortCosmeticVariant>> ItemVariants;

	UPROPERTY(EditAnywhere, Instanced, Category="Extensibility", meta=(AssetBundles="Equipped", TitleProperty="DataTitleString"))
	TArray<TObjectPtr<UFortCosmeticItemAdditionalData>> AdditionalDataFields;

	UPROPERTY(EditAnywhere, Category="Cosmetics", meta=(BaseStruct="/Script/CosmeticsFrameworkItems.CosmeticPropertyBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> BaseCosmeticProperties;

	UPROPERTY(EditAnywhere, Category="Variants", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag VariantChannelToUseForThumbnails;

	UPROPERTY(EditAnywhere, Category="Variants")
	bool bOverrideDefaultVariantPreviewTime;

	UPROPERTY(EditAnywhere, Category="Variants", meta=(EditCondition="bOverrideDefaultVariantPreviewTime"))
	float DefaultVariantPreviewOverrideTime;

	UPROPERTY(EditAnywhere, Category="Variants")
	TArray<FFortCosmeticVariantPreview> ItemVariantPreviews;

	UPROPERTY(EditAnywhere, Instanced, Category="Variants")
	TObjectPtr<UFortVariantPreviewGenerator> ItemVariantPreviewGenerator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variants")
	FText DirectAquisitionStyleDisclaimerOverride;

	UPROPERTY(EditAnywhere, Category="Visual|Overrides")
	TArray<FFortCosmeticAdaptiveStatPreview> ItemObservedStatPreviews;

	UPROPERTY(EditAnywhere, Category="Display", meta=(MultiLine="true"))
	FText UnlockRequirements;

	UPROPERTY(EditAnywhere, Category="Display")
	FText ItemVariantUnlockRequirements;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UFortAccountItemDefinition> UnlockingItemDef;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftClassPtr<AFortItemPreviewActor> ItemPreviewActorClass;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UFXSystemAsset> ItemPreviewParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Male;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Female;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UAthenaCharacterItemDefinition> ItemPreviewHero;

	UPROPERTY(Transient)
	TArray<FName> ConfiguredDynamicInstallBundles;

	UPROPERTY(Transient)
	TArray<FName> PendingDynamicInstallBundles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Exclusive Item")
	FGameplayTagContainer ExclusiveRequiresOutfitTags;

	UPROPERTY(EditDefaultsOnly, Category="Exclusive Item")
	FText CustomExclusiveCallout;

	UPROPERTY(EditDefaultsOnly, Category="Exclusive Item")
	FText ExclusiveDesciption;

	UPROPERTY(EditDefaultsOnly, Category="Exclusive Item")
	TSoftObjectPtr<UTexture2D> ExclusiveIcon;

#if WITH_EDITORONLY_DATA
	UPROPERTY(AssetRegistrySearchable)
	FString CosmeticSet;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(AssetRegistrySearchable)
	FString CosmeticSources;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(AssetRegistrySearchable)
	FString CosmeticTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(AssetRegistrySearchable)
	int32 CosmeticOrderingID;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="AthenaCosmeticItemDefinition")
	int32 BaseShotGridId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="AthenaCosmeticItemDefinition")
	TArray<int32> VariantShotGridIds;

	UPROPERTY(BlueprintReadOnly, AssetRegistrySearchable, Category="AthenaCosmeticItemDefinition")
	TArray<int32> ShotGridIds;

	UPROPERTY(EditDefaultsOnly, Category="AthenaCosmeticItemDefinition")
	TArray<FText> ItemSearchTags;

};

