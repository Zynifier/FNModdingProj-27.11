// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseProjectTypes.generated.h"

UENUM()
enum class EVersePackageScope : uint8
{
	InternalAPI = 0,
	// Created by Epic and is entirely hidden from public users

	PublicAPI = 1,
	// Created by Epic and only public definitions will be visible to public users

	User = 2,
};

UENUM()
enum class EVersePackageType : uint8
{
	VNI = 0,
	// A package associated with a C++ module

	Content = 1,
	// A package associated with a plugin

	PublishedContent = 2,
	// A package associated with the published content of a plugin

	Assets = 3,
};

// Settings of a package
// This mirrors CSourcePackage::SSettings in the compiler

USTRUCT()
struct FVersePackageContainerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString VersePath;

	// Verse path of the root module of this package

	UPROPERTY()
	EVersePackageScope VerseScope;

	// Origin/visibility of Verse code in this package

	UPROPERTY()
	TArray<FString> DependencyPackages;

	// Names of packages this package is dependent on

	UPROPERTY()
	FString VniDestDir;

};

USTRUCT()
struct FVerseSourceCode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> Code;

};

USTRUCT()
struct FVerseSourceFile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Filename;

	UPROPERTY()
	TArray<FVerseSourceCode> CodeChunks;

};

// Specification of a package embedded in a project file
// This mirrors SPackageDesc in the compiler

USTRUCT()
struct FVersePackageContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString DirPath;

	UPROPERTY()
	EVersePackageType PackageType;

	UPROPERTY()
	bool bEnableVerseAssetReflection;

	UPROPERTY()
	FVersePackageContainerSettings Settings;

	UPROPERTY()
	TArray<FVerseSourceFile> SourceFiles;

	UPROPERTY()
	TArray<uint8> AssetDigest;

	UPROPERTY()
	TArray<FString> AssetDependencies;

};

USTRUCT()
struct FVerseProjectContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVersePackageContainer> Packages;

};

