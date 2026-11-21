// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AboutModal.generated.h"

class UCommonButtonLegacy;
class UFortActivatableMovieWidget;
class UFortLazyImage;
class UFortStreamMediaSource;
class UObject;
class UScrollBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaAboutModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAboutModalClosedDynamic);

public:
	UPROPERTY(BlueprintAssignable)
	FOnAboutModalClosedDynamic BP_OnAboutModalClosed;

	UPROPERTY(BlueprintReadOnly, Category="AthenaAboutModal")
	bool bForceShowPage;

protected:
	UFUNCTION(BlueprintCallable)
	void CloseModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetContent(const FText& InTitle, const TArray<FText>& InEntries);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AthenaAboutModal")
	FText Title;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="AthenaAboutModal")
	TArray<FText> Entries;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AthenaAboutModal", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.Material,/Script/Engine.MaterialInstance"))
	TSoftObjectPtr<UObject> HeroImage;

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaAboutModal")
	TSoftClassPtr<UFortActivatableMovieWidget> SeasonMovieWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAboutModal")
	TObjectPtr<UFortStreamMediaSource> VideoStream_Source;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Content;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_Item;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BPSTrailer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BPSTrailer_Mobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BPSHowTo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaAboutModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_BPSHowTo_Mobile;

};

