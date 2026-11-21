// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "AthenaCollectionScreenBase.generated.h"

class UAthenaCollectionListEntry;
class UAthenaCollectionListView;
class UAthenaCollectionPlayerProgressContainer;
class UAthenaCollectionScreenInfoOverlay;
class UCommonButtonLegacy;
class UContentWidget;
class UFortCollectionData;
class UFortCollectionsDataTable;
class UObject;
class UScrollBox;

UCLASS(Abstract, MinimalAPI, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaCollectionScreenBase : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Finished Loading"))
	FORTNITEUI_API void BP_OnFinishedLoading();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Selected Entry Changed"))
	FORTNITEUI_API void BP_OnHandleSelectedEntryChanged(UAthenaCollectionListEntry* SelectedEntry);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Info Overlay Activated"))
	FORTNITEUI_API void BP_OnInfoOverlayActivated();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Info Overlay Deactivated"))
	FORTNITEUI_API void BP_OnInfoOverlayDeactivated();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Started Loading"))
	FORTNITEUI_API void BP_OnStartedLoading();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void CenterSelectedEntry();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void SetListViewColumnCount(const int32 InColumnCount);

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	bool bUseMcpProfileData;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaCollectionScreenInfoOverlay> InfoOverlay;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionsDataTable> CollectionsDataTable;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionData> CollectionData;

	UPROPERTY(BlueprintReadOnly, Category="AthenaCollectionScreenBase")
	FGameplayTagContainer CategoryTags;

	UPROPERTY(BlueprintReadOnly, Category="AthenaCollectionScreenBase")
	FText CategoryTitle;

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FText CollectionName;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FString CollectionType;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FString CollectionCategory;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FText UnknownText;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FText UnknownDescription;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftObjectPtr<UObject> KnownEntryImage;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftObjectPtr<UObject> UnknownEntryImage;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftObjectPtr<UObject> KnownOverlayImage;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftObjectPtr<UObject> UnknownOverlayImage;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftObjectPtr<UObject> SecondaryIconImage;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	FText PersonalBestTextFormat;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	uint8 PersonalBestMinimumFractionalDigits;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	uint8 PersonalBestMaximumFractionalDigits;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase")
	TSoftClassPtr<UAthenaCollectionScreenInfoOverlay> SoftInfoOverlayClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_List;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCollectionListView> CollectionListView;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UContentWidget> Content_InfoOverlayContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ToggleInfoOverlay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaCollectionPlayerProgressContainer> PlayerProgressContainer;

	UPROPERTY(BlueprintReadOnly, Category="AthenaCollectionScreenBase", meta=(AllowPrivateAccess))
	bool bWantsToShowInfoOverlay;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenBase", meta=(AllowPrivateAccess))
	bool bForceOverlayToggleMobile;

};

