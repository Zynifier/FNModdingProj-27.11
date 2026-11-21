// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaGroupChallengeTag.generated.h"

class UWidgetAnimation;

UCLASS()
class UAthenaGroupChallengeTag : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaGroupChallengeTag(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleOnToggleFullScreenMap(bool bIsMapVisible);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaGroupChallengeTag", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> Anim_Flash;

};

