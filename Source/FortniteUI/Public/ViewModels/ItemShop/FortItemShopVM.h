// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Misc/Timespan.h"
#include "MultiProductItemShop/FortItemShopCMSData.h"
#include "FortItemShopVM.generated.h"

class UFortItemShopOfferGroupVM;
class UFortItemShopOfferVM;
class UFortItemShopSectionVM;
class UFortSubscriptionVM;
class UObject;

USTRUCT(BlueprintType)
struct FFortItemShopLayout
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortItemShopLayout")
	FString SectionId;

	UPROPERTY(BlueprintReadWrite, Category="FortItemShopLayout")
	FString SubsectionId;

};

UCLASS()
class UFortItemShopVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnBackgroundLoaded, UObject*, LoadedBackground);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ClearItemShopBang() const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopOfferVM* FindOfferByTrackingId(const FString& OfferTrackingId) const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopOfferVM* GetFirstOfferVMFromLayout(const FFortItemShopLayout& InLayout) const;

	UFUNCTION(BlueprintPure)
	bool GetHasSeenItemShop() const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopOfferVM* GetOfferFromId(const FString& OfferId) const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopOfferGroupVM* GetOfferGroupWithOffer(const FString& OfferId) const;

	UFUNCTION(BlueprintPure)
	FFortItemShopCMSBackground GetPreferredBackgroundForLayout(const FFortItemShopLayout& InLayout) const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopSectionVM* GetSection(const FString& SectionId) const;

	UFUNCTION(BlueprintPure)
	const UFortItemShopSectionVM* GetSubsection(const FString& SubsectionId, const UFortItemShopSectionVM* ParentSection) const;

	UFUNCTION(BlueprintPure)
	bool IsItemPreviewEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsRufusOnePageShopEnabled() const;

	UFUNCTION(BlueprintCallable)
	bool LoadBackground(const FFortItemShopCMSBackground& Background, const FOnBackgroundLoaded& OnLoadedCallback);

	UFUNCTION(BlueprintPure)
	bool MPItemShopPhase2Enabled() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void SetHasSeenItemShop(bool bHasSeen) const;

	UFUNCTION(BlueprintPure)
	bool ShouldShowNavPromptBelowNav() const;

	UFUNCTION(BlueprintPure)
	bool ShouldUseBattlePassLevelUpText() const;

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="RequestingObject"))
	void StartMonitoringForUpdates(const UObject* RequestingObject);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="RequestingObject"))
	void StopMonitoringForUpdates(const UObject* RequestingObject);

	UFUNCTION(BlueprintCallable)
	void UpdateContentOrdering();

private:
	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopSectionVM>> Sections;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopSectionVM>> SectionsWithOffers;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortItemShopOfferGroupVM>> AllOfferGroupsWithOffers;

	UPROPERTY(BlueprintReadWrite, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	FString FeaturedOfferId;

	UPROPERTY(BlueprintReadWrite, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	FFortItemShopLayout FeaturedLayout;

	UPROPERTY(BlueprintReadWrite, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	FString PreviewedItemTemplateId;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	FString AffiliateName;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	FTimespan ShopRefreshTimespan;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	bool bCatalogRefreshing;

	UPROPERTY(BlueprintReadOnly, Category="FortItemShopVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortSubscriptionVM> SubscriptionVM;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UObject>> MonitorForUpdatesRequesters;

};

