// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortProgressModal.generated.h"

class UFortProgressWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortProgressModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetDescription(const FText& InDescription);

	UFUNCTION(BlueprintCallable)
	void SetIcon(FSlateBrush InIcon);

	UFUNCTION(BlueprintCallable)
	void SetTitle(const FText& InTitle);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	FSlateBrush Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	bool bIntroOutroEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	bool bAutoInitialize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	bool bFocusSelf;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortProgressModal", meta=(ExposeOnSpawn="TRUE"))
	bool bConsumeAnalogInput;

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void InitializeModal();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressWidget> ProgressWidget_Main;

};

