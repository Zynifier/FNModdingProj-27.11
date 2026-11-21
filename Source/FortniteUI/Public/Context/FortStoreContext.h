// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortRarityEnum.h"
#include "FortUITypes.h"
#include "McpCatalogEnums.h"
#include "FortStoreContext.generated.h"

class UFortAccountItemDefinition;
class UFortCardPackItem;
class UFortCardPackItemDefinition;
class UFortItem;
class UFortItemDefinition;
enum class EFortStoreState : uint8;

UENUM()
enum class ECardPackPurchaseError : uint8
{
	PendingServerConfirmation = 0,
	// this is "success" for all intents, wait for the callback to know for sure

	CannotAffordItem = 1,
	NoneLeft = 2,
	PurchaseAlreadyPending = 3,
	NoConnection = 4,
};

UENUM(BlueprintType)
enum class EPauseType : uint8
{
	NoPause = 0,
	Rare = 1,
	New = 2,
	NewAndRare = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStorePurchaseCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStoreSkipOpenChangedDelegate, bool, bSkipOpening);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStoreStateChangedDelegate, EFortStoreState, NewStoreState);

USTRUCT(BlueprintType)
struct FCard
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Card")
	int32 QuantityReceived;

	UPROPERTY(BlueprintReadOnly, Category="Card")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="Card")
	EPauseType PauseType;

};

USTRUCT(BlueprintType)
struct FCardPackOffer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	FText Title;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	FText Description;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	int32 MtxPrice;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	TEnumAsByte<ECatalogSaleType::Type> SaleType;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	FText SaleText;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	int32 Price;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	int32 RegularPrice;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	TObjectPtr<UFortAccountItemDefinition> CurrencyType;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	int32 QuantityRemaining;

	UPROPERTY(BlueprintReadOnly, Category="CardPackOffer")
	bool bTimedOffer;

};

USTRUCT(BlueprintType)
struct FOpenedCardPack
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="OpenedCardPack")
	TObjectPtr<UFortCardPackItemDefinition> CardPackDefinition;

	UPROPERTY(BlueprintReadOnly, Category="OpenedCardPack")
	int32 DisplayLevel;

};

USTRUCT(BlueprintType)
struct FStoreCallout
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Callout")
	FFortToastDisplayInfo ToastDisplayInfo;

	UPROPERTY()
	FText ItemName;

	UPROPERTY()
	FText ItemSet;

	UPROPERTY(Transient)
	FString OfferDisplayAssetPath;

	UPROPERTY()
	FName LayoutId;

};

UCLASS()
class FORTNITEUI_API UFortStoreContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardAddedToSummaryComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardBackRevealComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardEntryComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardExitComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardFlipComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardFrontRevealComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardPackDestroyComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool CardPackOpeningComplete();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool ChoiceResultComplete();

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool DoesItemSlotExistInCollectionBook(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool EnterCurrencyStore();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool ExitCurrencyStore();

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool ExitSummary();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="StoreContext")
	void FireInteractionAnalyticsEvent(const FString& Interaction, const FString& Details = TEXT("")) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool GetCard(int32 CardIdx, FCard& ResultOut) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	TArray<FCard> GetChoiceCards(int32 CardIdx) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	int32 GetNumUnopenedCardPacksRemaining(const UFortCardPackItemDefinition* PackType = nullptr, bool bCountChoicePacks = true) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	int32 GetOwnedItemCount(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	int32 GetOwnedSurvivorCount(const UFortItem* SurvivorItem) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	int32 GetPackOpeningLimit() const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool GetSkipOpening() const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	EFortStoreState GetStoreState() const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool IsItemMissingFromCollectionBook(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool IsOpeningDirectPack() const;

	UFUNCTION(BlueprintPure, Category="StoreContext")
	bool IsWaitingForMcp() const;

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	bool MakeChoice(int32 ChoiceIdx, UFortAccountItemDefinition* ChoiceItemDefinition);

	UFUNCTION(BlueprintCallable, Category="StoreContext")
	void SetSkipOpening(const bool bSkipOpen);

	UPROPERTY(BlueprintAssignable, Category="StoreContext")
	FStoreStateChangedDelegate OnStoreStateChange;

	UPROPERTY(BlueprintAssignable, Category="StoreContext")
	FStoreSkipOpenChangedDelegate OnStoreSkipOpenChanged;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreContext")
	TArray<FCardPackOffer> Offers;

	UPROPERTY()
	TArray<FCard> CardList;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreContext")
	int32 CardIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreContext")
	FOpenedCardPack OpenedCardPack;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreContext")
	EFortRarity LastCardRarity;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreContext")
	TArray<FCard> PurchasedItemList;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCardPackItem>> PurchasedCardPacks;

};

