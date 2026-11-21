// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "Components/SlateWrapperTypes.h"
#include "Styling/SlateBrush.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortTabListWidgetBase.generated.h"

class UCommonButtonBase;
class UCommonUserWidget;
class UObject;
class UUserWidget;
class UWidget;

USTRUCT(BlueprintType)
struct FFortTabButtonLabelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTabButtonLabelInfo")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTabButtonLabelInfo")
	FSlateBrush IconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTabButtonLabelInfo", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> IconResource;

	UPROPERTY(EditAnywhere, Category="FortTabButtonLabelInfo")
	FFortPrioritizedWidgetData PriorityData;

};

USTRUCT(BlueprintType)
struct FFortTabListRegistrationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	FName TabNameId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	bool bHidden;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	bool bAllowedInZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	FFortTabButtonLabelInfo TabLabelInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	TSubclassOf<UCommonButtonBase> TabButtonType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTabListRegistrationInfo")
	TSubclassOf<UCommonUserWidget> TabContentType;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> CreatedTabContentWidget;

};

UINTERFACE(MinimalAPI, BlueprintType)
class UFortTabButtonInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortTabButtonInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Fort Tab Button")
	void SetTabLabelInfo(const FFortTabButtonLabelInfo& TabLabelInfo);

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortTabListWidgetBase : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTabContentCreated, FName, TabId, UCommonUserWidget*, TabWidget);

public:
	UFUNCTION(BlueprintPure, Category="Tab List")
	bool GetPreregisteredTabInfo(const FName TabNameId, FFortTabListRegistrationInfo& OutTabInfo);

	UFUNCTION(BlueprintPure, Category="Tab List")
	int32 GetVisibleTabCount() const;

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsFirstTabActive() const;

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsLastTabActive() const;

	UFUNCTION(BlueprintPure, Category="Tab List")
	bool IsTabVisible(const FName TabId) const;

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void RegisterAllPreregisteredTabInfos();

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void RegisterDivider(const TSubclassOf<UUserWidget> DividerWidgetType);

	UFUNCTION(BlueprintCallable, Category="Tab List")
	bool RegisterFortTab(const FName TabNameId, const TSubclassOf<UCommonButtonBase> TabButtonType, const FFortTabButtonLabelInfo& LabelInfo, UWidget* ContentWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="Tab List")
	void RemoveAllDividers();

	UFUNCTION(BlueprintCallable, Category="Tab List")
	void SetTabHiddenState(const FName TabNameId, const bool bHidden);

	UPROPERTY(BlueprintAssignable, Category="Tab List")
	FOnTabContentCreated OnTabContentCreated;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Tab List", meta=(BlueprintProtected="true"))
	void HandleDividerCreation(UUserWidget* DividerWidget);

private:
	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase")
	TArray<FFortTabListRegistrationInfo> PreregisteredTabInfoArray;

	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase", meta=(InlineEditConditionToggle="HiddenVisibility"))
	bool bHideSingleTab;

	UPROPERTY(EditAnywhere, Category="FortTabListWidgetBase", meta=(EditCondition="bHideSingleTab"))
	ESlateVisibility HideSingleTabVisibility;

	UPROPERTY(Transient)
	TMap<FName, FFortTabButtonLabelInfo> RegisteredFortTabsById;

};

