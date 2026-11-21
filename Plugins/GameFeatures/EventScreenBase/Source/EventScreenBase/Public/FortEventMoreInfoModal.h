// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEventModalBase.h"
#include "FortEventMoreInfoModal.generated.h"

class UCommonButtonBase;
class UDynamicEntryBox;
class UFortEventScreenData;
class UScrollBox;
class UTexture2D;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortEventMoreInfoGroup : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEventMoreInfoGroup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIconLoaded(const UTexture2D* Icon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetGroupText(const FText& Header, const FText& Body);

};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortEventMoreInfoModal : public UFortEventModalBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

	UFUNCTION(BlueprintImplementableEvent)
	void SetModalText(const FText& Header, const FText& SubHeader, const FText& Legal);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventMoreInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Groups;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventMoreInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventMoreInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseMobile;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventMoreInfoModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> SB_Vertical;

};

