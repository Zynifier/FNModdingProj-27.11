// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionPointWidget.generated.h"

class AActor;
class UTextBlock;
class UWidgetSwitcher;

UCLASS(meta=(DisableNativeTick))
class UInteractionPointWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UInteractionPointWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void StartDistanceUpdateTimer();

	UFUNCTION(BlueprintCallable)
	void StopDistanceUpdateTimer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="InteractionPointWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_Icons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointWidget")
	TArray<float> IconSwitchDistances;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="InteractionPointWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointWidget")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget")
	bool bScaleIconByDistance;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget", meta=(EditCondition="bScaleIconByDistance"))
	float MinIconScale;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget", meta=(EditCondition="bScaleIconByDistance"))
	float MinIconScaleDistance;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget", meta=(EditCondition="bScaleIconByDistance"))
	float MaxIconScale;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget", meta=(EditCondition="bScaleIconByDistance"))
	float MaxIconScaleDistance;

	UPROPERTY(EditAnywhere, Category="InteractionPointWidget")
	float HideIconWhenCloseDistance;

protected:
	UFUNCTION()
	void SetDistanceText(float Distance);

	UFUNCTION()
	void UpdateDistance();

	UPROPERTY(BlueprintReadWrite, Category="InteractionPointWidget")
	float DistanceUpdateInterval;

	UPROPERTY()
	bool bValidSwitcher;

};

