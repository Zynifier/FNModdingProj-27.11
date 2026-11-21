// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortMatchmakingKnobsDataSource.h"
#include "FortMatchmakingKnobsModal.generated.h"

class AActor;
class AFortPlayerPawn;
class IFortActorLabelOverrideInterface;
class IUserOptionValuesInterface;
class UCommonListView;
class UCommonTextBlock;
class UFortActorOptionsComponent;
class UFortCreativePropertySubcategoryHeaderListItem;
class UFortMatchmakingKnobsSpinnerButton;
class UImage;
class UObject;
class UPlaylistUserOptions;
class UUserWidget;
enum class EFortModifiedStatus : uint8;

UENUM(BlueprintType)
enum class EFortModifiedStatus : uint8
{
	IsDefault = 0,
	/* The value is the same as the default value. */
	IsModified = 1,
	/* The value is modified from the default value. */
	Unsupported = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchmakingKnobsModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetScrolledOffWhitelistedPlayers();

	UFUNCTION(BlueprintPure)
	FString GetSearchString() const;

	UFUNCTION(BlueprintCallable)
	void GetSearchStringFilteredOptionCategoryTags(FGameplayTagContainer& OutSearchStringFilteredOptionCategoryTags);

	UFUNCTION(BlueprintNativeEvent)
	void HandleCancelClicked();

	UFUNCTION(BlueprintCallable)
	virtual void InitForToyOptionsActor(AActor* InActor);

	UFUNCTION(BlueprintCallable)
	virtual void InitializeData();

	UFUNCTION(BlueprintCallable)
	void OnAcceptAnimationComplete(const bool bApplyAllOptions = false);

	UFUNCTION(BlueprintCallable)
	void OnCurrentItemSelectionChanged(UObject* Item);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectionUpdated(UFortMatchmakingKnobsSpinnerButton* CurrentSelection);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetInGameMode();

	UFUNCTION(BlueprintCallable)
	void SetListDataSource(UFortMatchmakingKnobsDataSource::Type ListType);

	UFUNCTION(BlueprintCallable)
	void SetOptionCategoryTagFilter(const FGameplayTagContainer& InOptionCategoryTagFilter);

	UFUNCTION(BlueprintCallable)
	void SetSearchString(const FString& InSearchString);

	UPROPERTY(EditAnywhere, Category="FortMatchmakingKnobsModal")
	float MobileOptionListEntrySpacing;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ApplyChanges(const bool bApplySettingsFromCachedData = false, const bool bApplyAllOptions = false);

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Label Override Interface"))
	TScriptInterface<IFortActorLabelOverrideInterface> BP_GetLabelOverrideInterface() const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Options Component"))
	UFortActorOptionsComponent* BP_GetOptionsComponent() const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get User Option Values Interface"))
	TScriptInterface<IUserOptionValuesInterface> BP_GetUserOptionValuesInterface() const;

	UFUNCTION(BlueprintCallable)
	static bool DoesContainString(const UObject* Option, const FString& String);

	UFUNCTION(BlueprintPure)
	EFortModifiedStatus GetModificationStatus(const UObject* Option) const;

	UFUNCTION(BlueprintPure)
	EFortModifiedStatus GetSpinnerModificationStatus(const UFortMatchmakingKnobsSpinnerButton* SpinnerButton) const;

	UFUNCTION(BlueprintCallable)
	virtual void HandleRestoreEventsClicked();

	UFUNCTION(BlueprintCallable)
	virtual void HandleRestoreFunctionsClicked();

	UFUNCTION(BlueprintCallable)
	virtual void HandleRestorePropertiesClicked();

	UFUNCTION(BlueprintPure)
	bool HasEventDescriptorProperty() const;

	UFUNCTION(BlueprintPure)
	bool HasEventFunctionProperty() const;

	UFUNCTION(BlueprintCallable)
	static bool HasMatchingTags(const UObject* Option, const FGameplayTagContainer& CategoryTags, const FGameplayTagContainer& ContextTags);

	UFUNCTION(BlueprintPure)
	bool HasNonEventProperties() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDataInitialized();

	UFUNCTION(BlueprintImplementableEvent)
	bool OnHandleRestoreDefaultsInput();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitForOptionsComponent(UFortActorOptionsComponent* OptionsComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitForUserOptionValues(const TScriptInterface<IUserOptionValuesInterface>& UserOptionValues);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOptionsFiltered();

	UFUNCTION(BlueprintCallable)
	virtual void RestoreOptionsToDefault(const bool bRestoreAllOptions);

	UPROPERTY(Transient)
	TArray<FString> ScrolledOffWhitelistedPlayers;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingKnobsModal")
	bool bInitializeDataInNativeConstruct;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> OptionsList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_TitleText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_DescriptionText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_DisplayImage;

private:
	UFUNCTION()
	void HandleForcedOffIsland();

	UFUNCTION()
	void HandleLeaveIsland(AFortPlayerPawn* PlayerPawn);

	UFUNCTION()
	void OnHoveredItemChanged(UObject* Item, bool bIsHovered);

	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptions> OptionsAsset;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> OptionDataProviders;

	UPROPERTY(Transient)
	TMap<FString, FString> LoadedOptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMatchmakingKnobsModal", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RestoreDefaultsInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingKnobsModal")
	TSubclassOf<UUserWidget> SubcategoryHeaderWidgetClass;

	UPROPERTY(EditInstanceOnly, Category="FortMatchmakingKnobsModal")
	bool bBindToOnLoadedOptionsChanged;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UFortCreativePropertySubcategoryHeaderListItem>> SubcategoryHeaderTagToListItems;

};

