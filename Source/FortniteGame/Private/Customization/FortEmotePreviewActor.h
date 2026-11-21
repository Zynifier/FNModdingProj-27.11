// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortEmotePreviewActor.generated.h"

class UFortMontageItemDefinitionBase;

UCLASS(Abstract, BlueprintType)
class AFortEmotePreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Emote")
	void PreviewEmote(const UFortMontageItemDefinitionBase* Emote);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortMontageItemDefinitionBase> PreviewingEmote;

};

