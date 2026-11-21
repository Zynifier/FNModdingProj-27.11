// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "CommonButtonBase.h"
#include "CommonListView.h"
#include "UObject/NoExportTypes.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "FortContentManagementList.generated.h"

class UFortContentManagementLabelWidget;
class UFortContentManagementListView;
class UFortGameActivity;
enum class EFortContentManagementState : uint8;

UENUM(BlueprintType)
enum class EFortContentManagementState : uint8
{
	Locked = 0,
	Unlocked = 1,
	WaitingForResponse = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class SQUEEGEEUI_API UFortContentManagementButton : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChangeManagementState(EFortContentManagementState NewState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowError(const FText& ErrorText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowGameActivity(const UFortGameActivity* NewGameActivity);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowWeaponManagement();

};

UCLASS()
class UFortContentManagementEntryDataObject : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UFortContentManagementEntryLabelObject : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortContentManagementLabelWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFortContentManagementLabelWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetLabel(const FText& InText);

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class SQUEEGEEUI_API UFortContentManagementList : public UFortSqueegeeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool CanRequestNextUnlockPage() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNextUnlockPageRequestCompleted(bool bSuccess);

	UFUNCTION(BlueprintCallable)
	void RequestNextUnlockPage();

	UFUNCTION(BlueprintCallable)
	void ResetUnlockList();

	UPROPERTY(EditAnywhere, Category="FortContentManagementList")
	FText WeaponLabelText;

	UPROPERTY(EditAnywhere, Category="FortContentManagementList")
	FText GameModeLabelText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortContentManagementList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortContentManagementListView> ContentManagementListView;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortGameActivity>> CachedActivities;

};

UCLASS()
class UFortContentManagementListView : public UCommonListView
{
	GENERATED_BODY()

public:
	UFortContentManagementListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="FortContentManagementListView")
	TSubclassOf<UFortContentManagementLabelWidget> LabelWidget;

};

