// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Creative/CreativeEditablePropertyInterface.h"
#include "Creative/FortCreativeToyOptionInterface.h"
#include "FortCreativeDeviceButtonComponent.generated.h"

class AFortPlayerControllerAthena;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonRefreshRequestedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeviceButtonClickedDelegate, AFortPlayerControllerAthena*, InstigatingController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeviceButtonDescriptionChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeviceButtonLabelChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeviceButtonNameChangedDelegate);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeDeviceButtonComponent : public UActorComponent, public IFortCreativeToyOptionInterface, public ICreativeEditablePropertyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void RequestButtonRefresh() const;

	UFUNCTION(BlueprintCallable, Category="Creative Device Button Component")
	void SetButtonDescription(const FText& InButtonDesciription);

	UFUNCTION(BlueprintCallable, Category="Creative Device Button Component")
	void SetButtonLabel(const FText& InButtonLabel);

	UFUNCTION(BlueprintCallable, Category="Creative Device Button Component")
	void SetButtonName(const FText& InButtonName);

	UPROPERTY(BlueprintAssignable)
	FOnDeviceButtonClickedDelegate OnDeviceButtonClickedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnDeviceButtonLabelChangedDelegate OnDeviceButtonLabelChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnDeviceButtonNameChangedDelegate OnDeviceButtonNameChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnDeviceButtonDescriptionChangedDelegate OnDeviceButtonDescriptionChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnButtonRefreshRequestedDelegate OnButtonRefreshRequested;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeDeviceButtonComponent")
	FGameplayTagContainer FilterTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeDeviceButtonComponent", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredFilterTagQuery;

private:
	UPROPERTY(EditDefaultsOnly, Category="Text")
	FText ButtonName;

	UPROPERTY(EditDefaultsOnly, Category="Text")
	FText ButtonDescription;

	UPROPERTY(EditDefaultsOnly, Category="Text")
	FText ButtonLabel;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	int32 WeightOffset;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> EditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDeviceButtonComponent")
	FGameplayTagContainer Tags;

};

