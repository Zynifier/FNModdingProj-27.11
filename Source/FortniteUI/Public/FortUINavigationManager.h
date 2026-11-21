// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Feature/FortUIFeature.h"
#include "FortInventoryFilterEnum.h"
#include "FortUINavigationManager.generated.h"

class UFortAccountItem;
class UFortCampaignHeroLoadoutItem;
class UFortItem;
class UFortItemTileView;
class UFortQuestItem;
class UObject;
class UUserWidget;
class UWidget;
enum class EFortFrontendInventoryFilter : uint8;
enum class EFortInventoryFilter : uint8;
enum class EFortItemInspectionMode : uint8;
enum class EFortUIFeature : uint8;
enum class EFortUINavigationOp : uint8;
enum class EFrontEndCamera : uint8;

UENUM(BlueprintType)
enum class EFortUINavigationOp : uint8
{
	PopContentStack = 0,
	FeatureSwitch = 1,
	NavigateToSkillTree = 2,
	NavigateToSquadSlot = 3,
	NavigateToQuest = 4,
	NavigateToItemManagement = 5,
	NavigateToExpeditions = 6,
	NavigateToCollectionBook = 7,
	None = 8,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortCollectionBookOp);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortExpeditionsOp);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortFeatureNavigateOp, EFortUIFeature, Feature);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortItemEvolutionNavigateRequest, UFortAccountItem*, Item);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortItemManagementScreenOp, EFortFrontendInventoryFilter, Filter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortNodePageNavigateRequest, FName, PageId, FName, NodeId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortPopContentStackOp);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortQuestItemNavigateRequest, UFortQuestItem*, QuestItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortQuestItemOp, UFortQuestItem*, QuestItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortSquadOp, FName, SquadId, int32, SquadSlotIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortSquadSlotNavigateRequest, FName, SquadId, int32, SquadSlotIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortTabNavigateRequest, EFrontEndCamera, State);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortVaultItemNavigateRequest, UFortAccountItem*, Item);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortVaultTabNavigateRequest, EFortInventoryFilter, VaultTab);

USTRUCT(BlueprintType)
struct FUINavigationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TObjectPtr<UObject> ObjectData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FName IdData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	int32 IntData;

};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FUINavigateDelegate, FUINavigationData, Data);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUINavigateGlobalDelegate, FUINavigationData, Data);

USTRUCT(BlueprintType)
struct FFortUINavigationOperation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	EFortUINavigationOp Operation;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	FName SquadId;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	int32 SquadSlotIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	FName PageId;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	FName NodeId;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	EFortUIFeature Feature;

	UPROPERTY(BlueprintReadOnly, Category="FortUINavigationOperation")
	EFortFrontendInventoryFilter ItemManagementFilter;

};

USTRUCT()
struct FFortUINavigationRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortUINavigationOperation> Operations;

};

USTRUCT()
struct FUINavigationEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUINavigationData Data;

	UPROPERTY()
	FUINavigateDelegate NavigateToDelegate;

	UPROPERTY()
	FUINavigateDelegate NavigateFromDelegate;

};

UCLASS(MinimalAPI)
class UUINavigationManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	void ClearStack();

	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	FText GetDisplayName(int32 Index);

	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	int32 GetStackSize();

	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	void NavigationToIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	void PopNavigation();

	UFUNCTION(BlueprintCallable, Category="UI Navigation")
	void PushNavigation(FText DisplayName, UObject* ObjectData, FName IdData, int32 IntData, const FUINavigateDelegate& OnNavigateTo, const FUINavigateDelegate& OnNavigateFrom);

	UPROPERTY(BlueprintAssignable, Category="UI Navigation")
	FUINavigateGlobalDelegate OnNavigationEvent;

private:
	UPROPERTY(Transient)
	TArray<FUINavigationEntry> NavigationStack;

};

UCLASS()
class FORTNITEUI_API UFortUINavigationManager : public UUINavigationManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	bool AttemptMatchmakeForQuest(UFortQuestItem* Quest, bool& OutContentNotDownloaded);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	bool AttemptPlayQuest(UFortQuestItem* Quest);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	bool CanNavigateToQuestObjective(UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void CenterWidget(UWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void CompletePendingNavigationOp(EFortUINavigationOp NavigationOp);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	bool HasPendingNavigationOp(EFortUINavigationOp NavigationOp);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void NavigateToFeature(EFortUIFeature Feature);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void NavigateToItemManagementScreen(EFortFrontendInventoryFilter Filter);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void PushHeroLoadoutScreen(UFortCampaignHeroLoadoutItem* HeroLoadout);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView = nullptr, bool bReadOnly = false, bool bAllowFavoriting = true, bool bIsTemporaryItem = false, bool bAllowRarityUpgrading = true);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void PushItemManagementScreen(EFortFrontendInventoryFilter ItemManagementFilter, UFortItem* ItemToSelect, bool bShowAutoMulch = false);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	void SetScrollWidget(UWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Navigation")
	bool TryGetPendingNavigationOp(FFortUINavigationOperation& NavigationOp);

	UPROPERTY(BlueprintAssignable, Category="Fort UI Navigation")
	FFortFeatureNavigateOp OnFeatureNavigateOp;

	UPROPERTY(BlueprintAssignable, Category="Fort UI Navigation")
	FFortSquadSlotNavigateRequest OnSquadSlotNavigateRequest;

	UPROPERTY(BlueprintAssignable, Category="Fort UI Navigation")
	FFortPopContentStackOp OnPopContentStackOp;

	UPROPERTY(BlueprintAssignable, Category="Fort UI Navigation")
	FFortSquadOp OnSquadNavigationOp;

private:
	UPROPERTY()
	TArray<FFortUINavigationRequest> NavigationRequests;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> HiddenCursorWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> VirtualCursorWidget;

};

