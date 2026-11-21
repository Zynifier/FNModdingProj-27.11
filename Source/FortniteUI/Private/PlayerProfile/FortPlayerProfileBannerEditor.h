// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortPlayerProfileBannerEditor.generated.h"

class UCommonButtonBase;

UENUM()
enum class ESaveProfileForBanners : int32
{
	SaveTheWorld = 0,
	BattleRoyale = 1,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerProfileBannerEditor : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPlayerProfileBannerEditor")
	ESaveProfileForBanners ProfileToSave;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerProfileBannerEditor")
	bool bCanCloseBannerEditor;

protected:
	UFUNCTION(BlueprintCallable, Category="Banner")
	void CommitChosenIconAndColor();

	UFUNCTION(BlueprintCallable, Category="Banner")
	void HandleEditorActivated();

	UFUNCTION(BlueprintCallable, Category="Banner")
	void HandleEditorDeactivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Banner")
	void OnShowNextCategory();

	UFUNCTION(BlueprintImplementableEvent, Category="Banner")
	void OnShowPreviousCategory();

	UFUNCTION(BlueprintNativeEvent, Category="Banner")
	void RefreshBannerEditor();

	UFUNCTION(BlueprintCallable, Category="Banner")
	void SetBannerColor(const FName& Color);

	UFUNCTION(BlueprintCallable, Category="Banner")
	void SetBannerIcon(const FName& Icon);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	TArray<FName> IconCategories;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	TArray<FName> ColorCategories;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	FName ChosenIcon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	FName ChosenIconCategory;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	FName ChosenColor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Banner")
	FName ChosenColorCategory;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerProfileBannerEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseEditorButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerProfileBannerEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_EditIcon;

};

