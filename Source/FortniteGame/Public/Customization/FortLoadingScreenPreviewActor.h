// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortLoadingScreenPreviewActor.generated.h"

class UAthenaLoadingScreenItemDefinition;
class UAthenaLoadingScreenPreviewPanel;

UCLASS(Abstract, MinimalAPI, BlueprintType)
class AFortLoadingScreenPreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="LoadingScreen")
	void PreviewLoadingScreen(const UAthenaLoadingScreenItemDefinition* LoadingScreen);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortLoadingScreenPreviewActor", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAthenaLoadingScreenPreviewPanel> FullScreenPreviewWidget;

	UPROPERTY()
	TObjectPtr<UAthenaLoadingScreenItemDefinition> DisplayedLoadingScreen;

};

