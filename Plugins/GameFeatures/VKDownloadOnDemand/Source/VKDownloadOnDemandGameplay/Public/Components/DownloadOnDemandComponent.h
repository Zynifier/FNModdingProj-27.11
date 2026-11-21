// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "DownloadOnDemandComponent.generated.h"

class UDownloadOnDemandPlot;
class UDownloadOnDemandProject;
class UDownloadOnDemandProjectContent;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UDownloadOnDemandComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleMnemonicsFromValkyriePaletteProviderReceived(const TArray<FString>& Mnemonics);

	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandPlot> Plot;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDownloadOnDemandProject>> UserOwnedProjects;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDownloadOnDemandProjectContent>> ShelvedContents;

};

