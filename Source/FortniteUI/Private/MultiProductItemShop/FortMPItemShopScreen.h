// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "FortMPItemShopScreen.generated.h"

class AFortItemPreviewWorld;
class UAthenaItemShopDisplayAssetOfferDetails;
class UAthenaItemShopOfferDetailsPreviewWidget;
class UAthenaScrollBox;
class UFortItemShopOfferGroupVM;
class UFortItemShopOfferVM;
class UFortItemShopVM;
class UObject;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortMPItemShopScreen : public UFortItemPreviewScreen
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UFortItemShopVM* GetItemShopVM();

protected:
	UFUNCTION(BlueprintCallable)
	void ClearItemPreview();

	UFUNCTION(BlueprintCallable)
	void HandleBackToGameRequested();

	UFUNCTION(BlueprintPure)
	bool IsItemShopDynamicBackgroundEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigateToOffer(const FString& OfferTrackingId, bool bShowOfferDetails);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScrollInput(const float ScrollAmount);

	UFUNCTION(BlueprintCallable)
	void RequestInspectOffer(UFortItemShopOfferVM* OfferVM, const UFortItemShopOfferGroupVM* OwningOfferGroupVM = nullptr);

	UFUNCTION(BlueprintCallable)
	void RequestItemPreview(const FString& InPreviewedItemTemplateId);

	UFUNCTION(BlueprintCallable)
	void RequestShowBattlePass();

	UFUNCTION(BlueprintCallable)
	void RequestShowCrewSubscription();

	UFUNCTION(BlueprintCallable)
	void UpdateBackground(UObject* LoadedBackground, const bool bPlayForward, const FLinearColor PrimaryColor = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000), const FLinearColor SecondaryColor = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000));

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortMPItemShopScreen")
	float PendingOfferPreviewDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortMPItemShopScreen")
	FLinearColor DefaultBackgroundPrimaryColor;

	UPROPERTY(EditDefaultsOnly, Category="FortMPItemShopScreen")
	FLinearColor DefaultBackgroundSecondaryColor;

	UPROPERTY(Transient)
	TObjectPtr<AFortItemPreviewWorld> CachedVaultWorld;

	UPROPERTY(EditAnywhere, Category="Item Inspection")
	TSoftClassPtr<UAthenaItemShopOfferDetailsPreviewWidget> ItemShopOfferDetailsScreenClass;

	UPROPERTY(EditAnywhere, Category="Item Inspection")
	TSoftClassPtr<UAthenaItemShopDisplayAssetOfferDetails> ItemShopDisplayAssetOfferDetailsClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMPItemShopScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Content;

};

