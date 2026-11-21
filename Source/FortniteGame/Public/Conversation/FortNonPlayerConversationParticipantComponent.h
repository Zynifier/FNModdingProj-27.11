// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationParticipantComponent.h"
#include "ConversationTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Conversation/FortConditionalBenefitsConfig.h"
#include "Conversation/NPCConversationDataTypes.h"
#include "Conversation/ServicePricingKeyRemapping.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortNonPlayerConversationParticipantComponent.generated.h"

class AActor;
class AFortPlayerController;
class UDataTable;
class UFortConditionalBenefitsConfigCollection;
class UFortConversationGiftTypeDefinitions;
class UFortConversationMemoryComponent;
class UFortQuestItemDefinition_Athena;
class UTexture2D;
class UUserWidget;
enum class EDialogMarkerInteractionState : uint8;

UENUM(BlueprintType)
enum class EDialogMarkerInteractionState : uint8
{
	Conversation = 0,
	InteractionRange = 1,
	IndicatorRange = 2,
	None = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogMarkerInteractionStateChanged, const EDialogMarkerInteractionState, CurrentInteractionState, const AFortPlayerController*, InteractingController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConversationEnded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterConversationState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReceivedLocalClientConversationMessage, const AFortPlayerController*, LocalPlayerController, const FClientConversationMessagePayload&, Message);

USTRUCT(BlueprintType)
struct FNPCQuestList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCQuestList")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition_Athena>> Quests;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortNonPlayerConversationParticipantComponent : public UConversationParticipantComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Interaction UI")
	void AddHideUIIndicatorReason(const FName& Reason);

	UFUNCTION(BlueprintPure, Category="Conversation")
	virtual bool CanStartConversationWith(const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void GiveItemsToPlayer(AFortPlayerController* RecipientPlayerController, const TArray<FNPCChosenItemData>& ItemsToGive);

	UFUNCTION(BlueprintPure, Category="Interaction UI")
	bool HasHideUIIndicatorReasons() const;

	UFUNCTION(BlueprintCallable, Category="Interaction UI")
	void RemoveHideUIIndicatorReason(const FName& Reason);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	void SelectItemsToGive(TArray<FNPCChosenItemData>& OutItemsSelectedData) const;

	UFUNCTION(BlueprintCallable, Category="Interaction UI")
	void ShowMessage(const FText& Message);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Conversation")
	void StartConversation(const FGameplayTag InConversationEntryTag, AActor* Instigator, AActor* Target) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TossItems(const TArray<FNPCChosenItemData>& ItemsToGive, const FVector& SpawnPickupLocation, const FVector& TossDirection, const float TossSpeed = 500.000000f, const float TossAngleVarianceDegrees = 20.000000f);

	UPROPERTY(BlueprintAssignable)
	FDialogMarkerInteractionStateChanged OnDialogMarkerInteractionStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnReceivedLocalClientConversationMessage OnReceivedLocalClientConversationMessage;

	UPROPERTY(BlueprintAssignable)
	FOnEnterConversationState OnEnterConversationStateDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnConversationEnded OnConversationEnded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	FGameplayTag ConversationEntryTag;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	FGameplayTag InteractorParticipantTag;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	FGameplayTag SelfParticipantTag;

	UPROPERTY(EditAnywhere, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	FGameplayTag ServiceProviderIDTag;

	UPROPERTY(EditAnywhere, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	FGameplayTag ConditionalBenefitsConfigIDTag;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	bool bShowNameWhenInRange;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	bool bShowIndicatorBubble;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	bool bShowNameplateOnPreview;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="FortNonPlayerConversationParticipantComponent")
	bool bShowConversationText;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	EFortQuestObjectiveStatEvent InitiateConversationStatEventType;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortConversationMemoryComponent> ConversationMemoryComponent;

private:
	UPROPERTY(EditDefaultsOnly, Category="Gifts", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCConversationGiftRow"))
	TObjectPtr<UDataTable> Gifts;

	UPROPERTY(EditDefaultsOnly, Category="Gifts")
	FGameplayTag GiftsSeasonDataTableTag;

	UPROPERTY(EditDefaultsOnly, Category="Gifts")
	TObjectPtr<UFortConversationGiftTypeDefinitions> GiftTypeDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="Gifts")
	FGameplayTag GiftTypeDefinitionsSeasonDataAssetTag;

	UPROPERTY(EditDefaultsOnly, Category="Gifts", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCGiftItemInventoryRow"))
	TObjectPtr<UDataTable> GiftItemInventory;

	UPROPERTY(EditDefaultsOnly, Category="Gifts")
	FGameplayTag GiftItemInventorySeasonDataTableTag;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	int32 MaxServices;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCDynamicServiceRow"))
	TObjectPtr<UDataTable> Services;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	FGameplayTag ServicesOverride;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCSaleInventoryRow"))
	TObjectPtr<UDataTable> SalesInventory;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	FGameplayTag SalesInventoryOverride;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCDiscountServicesRow"))
	TObjectPtr<UDataTable> DiscountTable;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCQuestRow"))
	TObjectPtr<UDataTable> QuestsTable;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	FGameplayTag ServicePricingKeyRemappingsTag;

	UPROPERTY(EditAnywhere, Category="Conversation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCServicePricingKeyRemapRow"))
	TObjectPtr<UDataTable> ServicePricingKeyRemappingsTable;

	UPROPERTY(EditDefaultsOnly, Category="ConditionalBenefits")
	TObjectPtr<UFortConditionalBenefitsConfigCollection> ConditionalBenefitsConfigCollection;

	UPROPERTY(EditDefaultsOnly, Category="ConditionalBenefits")
	FGameplayTag ConditionalBenefitsSeasonDataAssetTag;

	UPROPERTY(EditDefaultsOnly, Category="ConditionalBenefits")
	FFortServiceDiscountBenefitSettings ServiceDiscountBenefitSettings;

	UPROPERTY(EditDefaultsOnly, Category="Quests")
	bool bQuestsRequireProviderTagMatch;

	UPROPERTY(EditDefaultsOnly, Category="Quests", meta=(EditCondition="!bQuestsRequireProviderTagMatch"))
	int32 MaxQuestsToSupportFromSingleProvider;

	UPROPERTY(EditDefaultsOnly, Category="Quests")
	int32 MaxQuestsToSupportForSingleFilterCategory;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Interaction UI")
	bool bOverrideParticipantDisplayName;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Interaction UI", meta=(EditCondition="bOverrideParticipantDisplayName"))
	FText ParticipantDisplayNameOverride;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI", meta=(AllowedClasses="/Script/FortniteConversationUI.FortConversationMarker"))
	TSubclassOf<UUserWidget> CustomDialogMarkerClass;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI")
	FGameplayTag CustomDialogMarkerTag;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI")
	bool bOverrideRelativeLocation;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI", meta=(EditCondition="bOverrideRelativeLocation"))
	FVector RelativeLocationOverride;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI")
	bool bOverrideMaxDrawDistance;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI", meta=(EditCondition="bOverrideMaxDrawDistance"))
	float MaxDrawDistanceOverride;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI")
	bool bDialogMarkerBoundsAdjustmentEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Interaction UI")
	TSoftObjectPtr<UTexture2D> DialogMarkerIndicatorSoftIcon;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UFortQuestItemDefinition_Athena>> SupportedQuests;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FNPCQuestList> SupportedQuestsByFilterCategory;

	UPROPERTY(Transient)
	TArray<FSupportedService> SupportedServices;

	UPROPERTY(Transient)
	TArray<FNPCSaleInventoryRow> SupportedSales;

	UPROPERTY(Transient)
	TArray<FNPCConversationGiftRow> SupportedGiftTypes;

	UPROPERTY(Transient)
	TArray<FNPCGiftItemInventoryRow> SupportedGiftItems;

	UPROPERTY(Transient)
	FServicePricingKeyRemappings SupportedPricingKeyRemappings;

	UPROPERTY(Transient)
	TArray<FName> HideUIIndicatorReasons;

	UPROPERTY(Transient)
	TObjectPtr<UFortConversationGiftTypeDefinitions> ResolvedGiftTypeDefinitions;

	UPROPERTY(Transient)
	TObjectPtr<UFortConditionalBenefitsConfigCollection> ResolvedConditionalBenefitsConfigCollection;

	UPROPERTY(Transient)
	bool bServiceDataInitialized;

	UPROPERTY(Transient)
	TMap<FGameplayTag, float> GiftCooldownTimestamps;

};

