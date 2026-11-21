// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"
#include "FortInventoryFilterEnum.h"
#include "FortItemTier.h"
#include "FortRarityData.h"
#include "FortRarityEnum.h"
#include "FortReleaseVersion.h"
#include "Items/FortItemTypeEnum.h"
#include "Items/FortSeasonPostCopyInterface.h"
#include "McpItemDefinitionBase.h"
#include "SoundLibraryProviderInterface.h"
#include "UI/FortTooltipInterface.h"
#include "FortItemDefinition.generated.h"

class AActor;
class IFortInventoryOwnerInterface;
class UAbilitySystemComponent;
class UFortItem;
class UFortItemDefinition;
class UFortItemSeriesDefinition;
class UFortTooltip;
class UFortTooltipDisplayStatsList;
class UItemPreviewImageOverride;
class UMeshComponent;
class UObject;
class USkeletalMesh;
class UStaticMesh;
class UTexture2D;
enum class EFortItemTier : uint8;
enum class EFortItemType : uint8;
enum class EFortRarity : uint8;

UENUM()
enum class EFortTemplateAccess : uint8
{
	/** Accessible by all */
	Normal = 0,
	/** DEPRECATED */
	Trusted = 1 UMETA(Hidden),
	/** Instances of this template never visible to requests */
	Private = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortOnItemDefinitionCountChangedDelegate, UFortItemDefinition*, Definition, int32, Delta);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortOnItemDefinitionCountChangedForOwnerDelegate, TScriptInterface<IFortInventoryOwnerInterface>, InventoryOwner, UFortItemDefinition*, Definition, int32, Delta);

UCLASS(Abstract, BlueprintType)
class FORTNITEGAME_API UFortItemDefinition : public UMcpItemDefinitionBase, public IGameplayTagAssetInterface, public IFortTooltipInterface, public IFortSeasonPostCopyInterface, public ISoundLibraryProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Prm")
	void ClearPrmValues();

	UFUNCTION(Category="Event", meta=(CallInEditor="true"))
	void CopyTemplateIdToClipboard();

	UFUNCTION(BlueprintPure, Category="Utilities")
	UFortItem* CreateTemporaryInstanceFromExistingItemBP(UFortItem* ExistingItem, int32 Count = 1, int32 Level = -1) const;

	UFUNCTION(BlueprintPure, Category="Utilities", meta=(DisplayName="CreateTemporaryItemInstance"))
	UFortItem* CreateTemporaryItemInstanceBP(int32 Count = 1, int32 Level = -1) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Frontend")
	virtual void CustomizePreviewMesh(UMeshComponent* Mesh) const;

	UFUNCTION(BlueprintCallable, Category="Frontend")
	virtual void CustomizePreviewPrefab(AActor* PrefabInstance);

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TArray<FText> GetDescription() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FSoftObjectPath GetDisplayAssetPath() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FText GetDisplayName(bool bBaseName) const;

	UFUNCTION(BlueprintPure, Category="Tooltips")
	virtual UFortTooltipDisplayStatsList* GetDisplayStats() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FSoftObjectPath GetHiResDisplayAssetPath() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TSoftObjectPtr<UTexture2D> GetInactivePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual EFortItemType GetItemType() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FText GetItemTypeName(bool bUsePlural = false) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TSoftObjectPtr<UTexture2D> GetLargePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual int32 GetMaxNumStacks() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual int32 GetMaxStackSize(UAbilitySystemComponent* AbilityComp = nullptr) const;

	UFUNCTION(BlueprintPure, Category="Item", meta=(Keywords="TemplateId"))
	virtual FString GetPersistentName() const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual void GetPreviewAssets(TArray<TSoftObjectPtr<UObject>>& Assets) const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	FTransform GetPreviewMeshOffset() const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual bool GetPreviewPrefabAsset(TSoftClassPtr<AActor>& Asset) const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual bool GetPreviewPrefabAssetAtSubSlot(TSoftClassPtr<AActor>& Asset, const int32 InSubSlot) const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual bool GetPreviewSkeletalMeshAsset(TSoftObjectPtr<USkeletalMesh>& Asset) const;

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual bool GetPreviewStaticMeshAsset(TSoftObjectPtr<UStaticMesh>& Asset) const;

	UFUNCTION(BlueprintPure, Category="Prm")
	FString GetPrmParameterName() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FText GetQuantityDisplayName(const int32 Quantity) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual EFortRarity GetRarity() const;

	UFUNCTION(BlueprintPure, Category="Colors")
	FFortColorPalette GetRarityOrSeriesColors() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FText GetRichDescription() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FText GetShortDescription() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FText GetSingleLineDescription() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TSoftObjectPtr<UTexture2D> GetSmallPreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual FSlateBrush GetSmallPreviewImageBrush() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual EFortItemTier GetTier() const;

	UFUNCTION(BlueprintPure, Category="Tooltips")
	virtual TSubclassOf<UFortTooltip> GetTooltip(bool bSummaryTooltip = false) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TSoftObjectPtr<UTexture2D> GetWidePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	bool IsInventorySizeLimited() const;

	UFUNCTION(BlueprintPure, Category="Item")
	bool IsItemSyncShareable() const;

	UFUNCTION(BlueprintPure, Category="Prm")
	bool IsPrmValid() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual bool IsStackable() const;

#if WITH_EDITOR
	UFUNCTION()
	virtual bool SeasonPostCopyFixup(const int32 SeasonNum, const FFortReleaseVersion& ReleaseVersion, const FString& NewSeasonPluginRoot);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Item")
	void SetRawLargePreviewImage(TSoftObjectPtr<UTexture2D> InLargePreviewImage);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Item")
	void SetRawSmallPreviewImage(TSoftObjectPtr<UTexture2D> InSmallPreviewImage);
#endif

	UFUNCTION(BlueprintPure, Category="Frontend")
	virtual bool ShouldShowPreviewOnCurrentHero(const int32 InSubSlot) const;

	UFUNCTION(BlueprintPure, Category="Prm")
	bool ShouldTrackInPRM() const;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

	UPROPERTY(BlueprintAssignable, Category="FortItem")
	FFortOnItemDefinitionCountChangedDelegate OnItemCountChanged;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="FortItemDefinition")
	EFortItemType ItemType;

	UPROPERTY(EditDefaultsOnly, Category="FortItemDefinition")
	EFortItemType PrimaryAssetIdItemTypeOverride;

	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(DisplayAfter="SearchTags"))
	EFortInventoryFilter FilterOverride;

	UPROPERTY(EditAnywhere, Category="Display", meta=(DisplayAfter="FilterOverride"))
	EFortItemTier Tier;

	UPROPERTY(EditAnywhere, Category="Display", meta=(DisplayAfter="Tier"))
	EFortItemTier MaxTier;

	UPROPERTY(EditAnywhere, Category="Functionality", meta=(DisplayAfter="bForceAutoPickup"))
	EFortTemplateAccess Access;

	UPROPERTY()
	uint8 bIsAccountItem : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="ReleaseVersion")
	uint8 bNeverPersisted : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="TertiaryCategoryOverrideTags"))
	uint8 bAllowMultipleStacks : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="bAllowMultipleStacks"))
	uint8 bAutoBalanceStacks : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="bAutoBalanceStacks"))
	uint8 bAllowSwapSingleStack : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="MaxStackSize"))
	uint8 bForceAutoPickup : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bPrivateTemplate_DEPRECATED : 1;
#endif

	UPROPERTY(EditAnywhere, Category="InventoryLimit")
	uint8 bInventorySizeLimited : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	uint8 bAllowItemSyncShare : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText ItemTypeNameOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Display")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText QuantityDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText ShortDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display", meta=(MultiLine="true"))
	FText Description;

	UPROPERTY()
	FText DisplayNamePrefix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText SearchTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FName GiftBoxGroupName;

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview", meta=(DisplayAfter="FrontendPreviewInitialRotation"))
	float FrontendPreviewScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer AutomationTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	FGameplayTagContainer SecondaryCategoryOverrideTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	FGameplayTagContainer TertiaryCategoryOverrideTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(UIMax="999", UIMin="1"))
	FScalableFloat MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(UIMax="32000", UIMin="-1"))
	FScalableFloat PurchaseItemLimit;

	UPROPERTY(EditAnywhere, Category="Tooltips")
	TSoftClassPtr<UFortTooltip> TooltipClass;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ItemsInInventoryInZone"))
	TSoftObjectPtr<UFortTooltipDisplayStatsList> StatList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rating")
	FCurveTableRowHandle RatingLookup;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> WidePreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY()
	FSoftObjectPath DisplayAssetPath_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(AllowedTypes="FortMtxOfferData"))
	FPrimaryAssetId DisplayAssetPrimaryAssetId;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Display", meta=(AllowedClasses="/Script/FortniteUI.FortMtxOfferData"))
	FSoftObjectPath HiResDisplayAssetPath;
#endif

	UPROPERTY(EditAnywhere, Category="Display", meta=(DisplayAfter="DisplayAssetPrimaryAssetId"))
	EFortRarity Rarity;

	UPROPERTY(EditAnywhere, Category="Display", meta=(RowType="/Script/FortniteUI.OfferPopUpData"))
	FDataTableRowHandle PopupDetailsTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Series")
	TObjectPtr<UFortItemSeriesDefinition> Series;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Preview Image")
	TObjectPtr<UItemPreviewImageOverride> ItemPreviewImageOverride;

	UPROPERTY(EditDefaultsOnly, Category="PRM")
	FFortReleaseVersion PrmReportUntil;

	UPROPERTY(EditDefaultsOnly, Category="PRM")
	FString PrmParameterName;

private:
	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	FVector FrontendPreviewPivotOffset;

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	FRotator FrontendPreviewInitialRotation;

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	TSoftObjectPtr<UStaticMesh> FrontendPreviewMeshOverride;

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview")
	TSoftObjectPtr<USkeletalMesh> FrontendPreviewSkeletalMeshOverride;

};

