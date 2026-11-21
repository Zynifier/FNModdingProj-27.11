// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LiveLinkTypes.h"
#include "Customization/FortPlayerMannequin.h"
#include "FortLiveMannequin.generated.h"

class ULiveLinkRetargetAsset;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Materials"))
class FORTNITEEDITOR_API AFortLiveMannequin : public AFortPlayerMannequin
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void ApplyBodySubject(FLiveLinkSubjectName inBodySubject);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void ApplyFaceSubject(FLiveLinkSubjectName inFaceSubject);

	UPROPERTY(EditAnywhere, BlueprintSetter=ApplyFaceSubject, Category="LiveLink")
	FLiveLinkSubjectName FaceSubject;

	UPROPERTY(EditAnywhere, BlueprintSetter=ApplyBodySubject, Category="LiveLink")
	FLiveLinkSubjectName BodySubject;

	UPROPERTY(EditAnywhere, Category="LiveLink")
	TSubclassOf<ULiveLinkRetargetAsset> BodyRetargetAsset;

	UPROPERTY(EditAnywhere, Category="LiveLink")
	bool bUpdateInEditor;

	UPROPERTY(BlueprintReadWrite, Category="Rendering")
	bool bVisibil;

};

