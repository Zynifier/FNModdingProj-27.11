// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MakeDesignAsset/FortEditorTool_MakeItemAssetBase.h"
#include "FortEditorTool_MakeAthenaDance.generated.h"

class UAnimMontage;

UCLASS()
class UFortEditorTool_MakeAthenaDance : public UFortEditorTool_MakeItemAssetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(Category="Make Item", meta=(CallInEditor="true"))
	void MakeEmoteItemDefinition();

	UPROPERTY(EditAnywhere, Category="Emote", meta=(MustModify))
	TObjectPtr<UAnimMontage> EmoteAnimation;

	UPROPERTY(EditAnywhere, Category="Emote")
	TObjectPtr<UAnimMontage> EmoteAnimationFemaleOverride;

};

