// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortCommunityVotingTileCandidate.generated.h"

class UCommonLoadGuard;
class UImage;

UCLASS(Abstract)
class UFortCommunityVotingTileCandidate : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCommunityVotingTileCandidate(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AnimateImage();

	UFUNCTION(BlueprintCallable)
	void OnImageAnimationFinished();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Candidate;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> LoadGuard;

};

