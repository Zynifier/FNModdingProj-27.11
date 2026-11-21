// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "UObject/NoExportTypes.h"
#include "FortSetting.generated.h"

class UFortLocalPlayer;
class UFortSetting;
class UFortSettingDetailExtension;
class UFortSettingRegistry;

USTRUCT(BlueprintType)
struct FFortSettingClassExtensions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Extensions")
	TArray<TSoftClassPtr<UFortSettingDetailExtension>> Extensions;

};

USTRUCT(BlueprintType)
struct FFortSettingNameExtensions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Extensions")
	bool bIncludeClassDefaultExtensions;

	UPROPERTY(EditAnywhere, Category="Extensions")
	TArray<TSoftClassPtr<UFortSettingDetailExtension>> Extensions;

};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortSetting : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual FText GetDescriptionRichText() const;

	UFUNCTION(BlueprintPure)
	FString GetDevName() const;

	UFUNCTION(BlueprintPure)
	FText GetDisplayName() const;

	UFUNCTION(BlueprintCallable)
	ESlateVisibility GetDisplayNameVisibility();

	UFUNCTION(BlueprintPure)
	FText GetDynamicDetails() const;

	UFUNCTION(BlueprintPure)
	FText GetWarningRichText() const;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UFortSetting> SettingParent;

	UPROPERTY(Transient)
	TObjectPtr<UFortSettingRegistry> OwningRegistry;

	UPROPERTY()
	FFortSettingNameExtensions CustomExtensions;

};

