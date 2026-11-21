// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"
#include "FortCreativeTabGroup.generated.h"

class UAthenaScrollBox;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonButtonStyle;
class USoundBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeTabGroup : public UUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentTabChanged, int32, CurrentTabIndex);

public:
	UFortCreativeTabGroup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void NextTab();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSimpleTabButtonAdded(UCommonButtonBase* Button, const FText& TabName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabButtonAdded(UCommonButtonBase* Button, const FText& TabName, const FSlateBrush& TabIcon);

	UFUNCTION(BlueprintCallable)
	void PreviousTab();

	UPROPERTY(BlueprintAssignable)
	FOnCurrentTabChanged OnCurrentTabChanged;

protected:
	UPROPERTY(EditAnywhere, Category="FortCreativeTabGroup")
	TSubclassOf<UCommonButtonBase> TabButtonClass;

	UPROPERTY(EditAnywhere, Category="FortCreativeTabGroup")
	TObjectPtr<USoundBase> TabOnHoveredSound;

	UPROPERTY(EditAnywhere, Category="FortCreativeTabGroup")
	TObjectPtr<USoundBase> TabOnPressedSound;

	UPROPERTY(EditAnywhere, Category="FortCreativeTabGroup")
	TSubclassOf<UCommonButtonStyle> TabButtonStyle;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativeTabGroup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> Tab_Box;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeTabGroup")
	TObjectPtr<UCommonButtonGroupBase> TabGroup;

};

