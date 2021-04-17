//
//  SketchRuntime.h
//
//  Created by Satori Maru on 18.01.18.
//  Copyright © 2018年 usagimaru.
//

#ifndef SketchRuntime_h
#define SketchRuntime_h

#import <Cocoa/Cocoa.h>

@protocol TurboCoreMSDocumentPreviewGeneration;
@protocol TurboCoreMSDocumentWriter;
@protocol TurboCoreMSEventHandlerManager;
@protocol TurboCoreMSPersistentAssetCollection;
@protocol TurboCoreMSColor;
@protocol TurboCoreBCPopover;
@protocol TurboCoreBCPopoverDelegate;
@protocol TurboCoreMSColorInspector;
@protocol TurboCoreMSStackView;
@protocol TurboCoreMSModePickerView;
@protocol TurboCoreMSLayer;
@protocol TurboCoreMSTextLayer;
@protocol TurboCoreMSDocument;
@protocol TurboCoreMSDocumentData;
@protocol TurboCoreMSImmutableDocumentData;
@protocol TurboCoreMSImmutablePage;
@protocol TurboCoreMSPage;
@protocol TurboCoreMSContentDrawViewController;
@protocol TurboCoreMSContentDrawView;
@protocol TurboCoreMSInspectorController;
@protocol TurboCoreBCSideBarViewController;
@protocol TurboCoreBCSideBarViewControllerDelegate;
@protocol TurboCoreBCOutlineViewNode;

#pragma mark -

/// [v50]
@protocol TurboCoreMSDocumentPreviewGeneration <NSObject>

- (NSDictionary*)generatePreviewsForDocument:(id <TurboCoreMSImmutableDocumentData>)immutableDocumentData;

@end

#pragma mark -

@protocol TurboCoreMSDocument <NSObject>

@property(nonatomic) NSWindow *documentWindow;
@property(nonatomic) NSView *messageView;
@property(nonatomic) NSView *canvasPlaceholderView;
@property(nonatomic) NSView *inspectorPlaceholderView;
@property(weak, nonatomic) id splitViewController; // MSMainSplitViewController
@property(nonatomic) id actionsController; // MSActionController
@property(nonatomic) id badgeController; // MSBadgeController
@property(nonatomic) id toolbarConstructor; // MSToolbarConstructor
@property(nonatomic) id historyMaker; // MSHistoryMaker
@property(readonly, nonatomic) id cacheManager; // MSCacheManager
@property(nonatomic) NSViewController <TurboCoreMSInspectorController> *inspectorController;
@property(nonatomic) NSViewController <TurboCoreMSContentDrawViewController> *currentContentViewController;
@property(nonatomic) id <TurboCoreMSEventHandlerManager> eventHandlerManager;
@property(nonatomic) NSViewController <TurboCoreBCSideBarViewController> *sidebarController;

@property(nonatomic) id <TurboCoreMSDocumentData> documentData;
@property(readonly, nonatomic) id <TurboCoreMSImmutableDocumentData> immutableDocumentData;
@property(copy, nonatomic) id previousSelectedLayers; // MSLayerArray
@property(nonatomic) NSMutableDictionary *mutableUIMetadata;
@property BOOL cacheFlushInProgress;
@property double mostRecentCacheFlushingTime;

@property(nonatomic) CGFloat pageListHeight;
@property(nonatomic) NSDictionary *UIMetadata;
@property(nonatomic) CGFloat zoomValue;
@property(nonatomic) CGPoint scrollOrigin;
@property(readonly, nonatomic) NSColorSpace *colorSpace;
@property(readonly, nonatomic) NSColorSpace *canvasColorSpace;
@property(nonatomic) id cloudShare; // SCKShare
@property(readonly, nonatomic) NSString *cloudName;

- (id <TurboCoreMSDocument>)init;
- (void)awakeFromNib;
- (NSString*)windowNibName;
- (NSArray*)actionClasses;

+ (id)currentDocument;

- (id)pluginContext;
- (id)cloudDocumentKey;
- (id)hudDocumentData;
- (void)hudSetMonitor:(id)arg1;
- (id)hudClientName;

- (NSWindow*)window;
- (NSToolbar*)toolbar;
- (void)showWindows;
- (NSView<TurboCoreMSContentDrawView>*)contentDrawView;

- (void)close;
- (void)setDelegatesToNil;

- (BOOL)isLibraryDocument;
- (BOOL)isInspectorVisible;
- (BOOL)isLayerListVisible;
- (BOOL)isRulersVisible;
- (BOOL)inspectorIsMain;
- (BOOL)hasArtboards;

- (void)refreshWindowBadge;
- (void)reloadTouchBars;
- (void)refreshLayerListIfNecessary;
- (void)refreshSidebarWithMask:(unsigned long long)arg1;
- (void)updateSliceCount;
- (void)reloadInspector;
- (void)reloadView;
- (void)refreshOverlay;
- (void)refreshOverlayInRect:(CGRect)rect;
- (void)loadLayerListPanel;
- (void)loadInspectorPanel;

- (id <TurboCoreMSPage>)addBlankPage;
- (NSArray*)pages;
- (void)removePage:(id <TurboCoreMSPage>)page;
- (void)setCurrentPage:(id <TurboCoreMSPage>)page;
- (id <TurboCoreMSPage>)currentPage;
- (id)layerStyles;
- (id)artboards;
- (id)findCurrentArtboardGroup;
- (void)setCurrentArtboard:(id)artboard;
- (void)addLayer:(id <TurboCoreMSLayer>)layer changeName:(BOOL)changeName;
- (void)addLayer:(id <TurboCoreMSLayer>)layer;
- (void)offsetLayerIfNecessary:(id <TurboCoreMSLayer>)layer forInsertingInGroup:(id)arg2;
- (id)allExportableLayers;
- (void)exportSliceLayers:(id)arg1;
- (id)selectedLayers; // MSLayerArray

- (BOOL)writeToURL:(NSURL*)URL ofType:(id)type forSaveOperation:(unsigned long long)saveOperation originalContentsURL:(NSURL*)originalURL error:(NSError**)error;
//- (void)saveToURL:(NSURL*)URL ofType:(id)type forSaveOperation:(unsigned long long)saveOperation completionHandler:(CDUnknownBlockType)handler;

- (void)showMessage:(NSString*)message;

/// [v50] move to... -> TurboCoreMSDocumentPreviewGeneration
//- (NSDictionary*)generatePreviewsForDocument:(id <TurboCoreMSImmutableDocumentData>)immutableDocumentData;

/// [v50] move to... -> MSDocumentWriter
//- (NSData*)previewImageForDocument:(id <TurboCoreMSImmutableDocumentData>)immutableDocumentData page:(id <TurboCoreMSImmutablePage>)immutablePage rect:(CGRect)rect;

/// [v50] move to... -> MSDocumentWriter
//- (id)findLibraryPreviewArtboardForDocument:(id)document outPage:(id *)outPage;


- (void)historyMakerDidProgressHistory:(id)arg1;
- (void)historyMakerDidRevertHistory:(id)arg1;
- (void)historyMaker:(id)arg1 didApplyHistoryUpdate:(unsigned long long)arg2;
- (void)documentDidChange:(id)arg1;
- (void)commitHistoryIfNecessary:(id)arg1;
- (void)flushCachesIfNecessary;
- (id)duplicateAndReturnError:(id *)arg1;
- (void)resetDocumentData:(id)arg1;
- (void)unbindLayerSliceInteraction;
- (void)bindLayerSliceInteraction;

- (void)zoomValueDidChange;
- (void)windowWillClose:(id)arg1;
- (void)windowDidResignKey:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)windowDidEndSheet:(id)arg1;
- (void)windowWillBeginSheet:(id)arg1;
- (void)windowDidResize:(id)arg1;
- (void)windowControllerDidLoadNib:(id)arg1;
- (void)windowDidExitFullScreen:(id)arg1;
- (void)windowWillEnterFullScreen:(id)arg1;

@end

#pragma mark -

/// [v50]
@protocol TurboCoreMSDocumentWriter <NSObject, TurboCoreMSDocumentPreviewGeneration>

+ (id)metadataForNewFile;

@property(nonatomic) NSData *libraryPreview; // @synthesize libraryPreview=_libraryPreview;
@property(nonatomic) NSData *previewData; // @synthesize previewData=_previewData;
@property(nonatomic) id archiver; // MSJSONZippedArchiver
//@property(copy, nonatomic) CDUnknownBlockType previewGenerationBlock; // @synthesize previewGenerationBlock=_previewGenerationBlock;
@property(nonatomic) NSDictionary *UIMetadata;

- (id)initWithFileURL:(id)arg1;
- (id)init;
- (id)findLibraryPreviewArtboardForDocument:(id)document outPage:(id *)outPage;
- (NSData*)previewImageForDocument:(id <TurboCoreMSImmutableDocumentData>)immutableDocumentData page:(id <TurboCoreMSImmutablePage>)immutablePage rect:(CGRect)rect;
- (NSDictionary*)generatePreviewsForDocument:(id <TurboCoreMSImmutableDocumentData>)immutableDocumentData;

@end

#pragma mark -

@protocol TurboCoreMSDocumentData <NSObject>

@property(weak, nonatomic) id delegate; // MSDocumentDataDelegate
@property(nonatomic) id fontList; // MSFontList
@property(nonatomic) id cache; // BCCache
@property(nonatomic) NSDictionary *metadata;
@property(nonatomic) BOOL autoExpandGroupsInLayerList;
@property(nonatomic) id <TurboCoreMSPage> currentPage;
@property(readonly, nonatomic) NSArray *pages;
@property(readonly, nonatomic) NSDictionary *symbolMap;
@property(readonly, nonatomic) NSSet *unavailableFontNames;
@property(readonly, nonatomic) NSSet *fontNames;

- (BOOL)documentIsEmpty;
- (id <TurboCoreMSDocumentData>)documentData;

- (void)determineCurrentArtboard;
- (void)refreshOverlay;
- (void)refreshOverlayInRect:(CGRect)rect;
- (void)immediatelyShowSelectionForAllLayers;
- (void)temporarilyHideSelectionForLayers:(NSArray*)layers;
- (void)replaceExistingCreationMetadata;
- (void)setEnableSliceInteraction:(BOOL)arg1;
- (void)setEnableLayerInteraction:(BOOL)arg1;

- (NSArray*)images;
- (NSArray*)allArtboards;
- (NSArray*)allSymbols;
- (NSArray*)localSymbols;

- (void)replaceFonts:(NSArray*)fonts;

- (id)sharedObjectContainerOfType:(unsigned long long)arg1;
//- (void)enumerateForeignSymbolsWithLibraries:(id)arg1 block:(CDUnknownBlockType)arg2;
- (id)libraryForForeignSymbol:(id)arg1 inLibraries:(NSArray*)libraries;
- (id)addCopyOfInstanceMasterToDocumentIfNecessary:(id)arg1;
- (void)addSymbolMaster:(id)symbolMaster;
- (id)addCopyOfMasterToDocumentIfNecessary:(id)arg1;
- (id)symbolWithID:(id)ID;

- (id)symbolInstancesBySymbolID;
- (void)populateDictionary:(id)arg1 withChildrenOf:(id)arg2;
- (NSArray*)layersByObjectID;
- (id <TurboCoreMSLayer>)layerWithID:(id)ID;
- (void)layerTreeLayoutDidChange;
- (void)layerSelectionMightHaveChanged;
- (NSArray*)selectedLayers;
//- (void)sharedObjectDidChange:(struct MSModelObject *)arg1;

- (NSString*)nameForNewPage;
- (id <TurboCoreMSPage>)symbolsPageOrCreateIfNecessary;
- (id <TurboCoreMSPage>)symbolsPage;
- (id <TurboCoreMSPage>)addBlankPage;
- (void)addPage:(id <TurboCoreMSPage>)page;
- (void)removePages:(NSArray*)pages detachInstances:(BOOL)arg2;
- (void)setCurrentPageIndex:(NSUInteger)index;
- (NSArray*)defaultPagesArray;

- (void)copyPropertiesToObject:(id)object options:(unsigned long long)options;
- (void)object:(id)object didChangeProperty:(id)property;

- (void)convertToColorSpace:(unsigned long long)colorSpace;
- (void)assignColorSpace:(unsigned long long)colorSpace;
- (void)replaceInstancesOfColor:(id)color1 withColor:(id)color2 ignoreAlphaWhenMatching:(BOOL)matching replaceAlpha:(BOOL)replaceAlpha;
//- (void)enumerateColorConvertiblesIgnoringForeignSymbols:(CDUnknownBlockType)arg1;

//- (BOOL)enumerateLayersWithOptions:(unsigned long long)arg1 block:(CDUnknownBlockType)arg2;
//- (void)enumerateLayers:(CDUnknownBlockType)arg1;

- (id <TurboCoreMSLayer>)firstLayer;
- (id <TurboCoreMSLayer>)lastLayer;
- (id <TurboCoreMSLayer>)containedLayers;
- (id <TurboCoreMSLayer>)layerAtIndex:(NSUInteger)index;
- (BOOL)canContainLayer:(id <TurboCoreMSLayer>)layer;
- (NSUInteger)indexOfLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)containsNoOrOneLayers;
- (BOOL)containsLayers;
- (BOOL)containsMultipleLayers;
- (BOOL)containsOneLayer;
- (NSUInteger)containedLayersCount;

- (BOOL)canBeContainedByDocument;
- (BOOL)canBeContainedByGroup;

- (id)metadataForKey:(id)key object:(id)object;
- (void)storeMetadata:(id)metadata forKey:(id)key object:(id)object;

@end

#pragma mark -

@protocol TurboCoreMSImmutableDocumentData <NSObject>

@property(nonatomic) NSDictionary *symbolsIndexedByID;
@property(nonatomic) NSDictionary *metadata;
@property(readonly, nonatomic) id <TurboCoreMSImmutablePage> currentPage;
@property(readonly, nonatomic) NSArray *pages;

- (BOOL)wasSavedByOldVersion;
- (BOOL)wasSavedByTestVersion;

//+ (id)loadDocumentDataWithMetadata:(id)arg1 loadBlock:(CDUnknownBlockType)arg2;
+ (NSUInteger)traitsForPropertyName:(id)name;

- (id)usedFontNames;
- (id)pagesAndArtboardsMetadata;
- (id)localSymbols;
- (id)allSymbols;
- (id)allArtboards;
- (id)defaultPagesArray;

- (id)symbolWithID:(id)ID;
- (id)pageWithID:(id)ID;

- (NSArray*)containedLayers;
- (id <TurboCoreMSLayer>)firstLayer;
- (id <TurboCoreMSLayer>)lastLayer;
- (id <TurboCoreMSLayer>)layerAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)canContainLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)containsNoOrOneLayers;
- (BOOL)containsLayers;
- (BOOL)containsMultipleLayers;
- (BOOL)containsOneLayer;
- (NSUInteger)containedLayersCount;

- (BOOL)canBeContainedByDocument;
- (BOOL)canBeContainedByGroup;
- (id)subObjectsForTreeDiff;
- (void)trackColors:(id)arg1 withinHierarchyOf:(id)arg2 excludeForeignSymbols:(BOOL)arg3;
- (void)trackColors:(id)arg1 excludeForeignSymbols:(BOOL)arg2;

@end

#pragma mark -

@protocol TurboCoreMSPage <NSObject>

@property(nonatomic) id cachedSelectedLayers; // MSLayerArray
@property(nonatomic) NSArray *cachedArtboards;
@property(nonatomic) NSArray *cachedExportableLayers;
@property(copy, nonatomic) id grid; // MSSimpleGrid
@property(copy, nonatomic) id layout; // MSLayoutGrid
@property(copy, nonatomic) id verticalRulerData; // MSRulerData
@property(copy, nonatomic) id horizontalRulerData; // MSRulerData
@property(nonatomic) CGPoint rulerBase;
@property(nonatomic) BOOL includeInCloudUpload;
@property(nonatomic) double zoomValue;
@property(nonatomic) CGPoint scrollOrigin;
@property(readonly, nonatomic) CGRect contentBounds;
@property(readonly, nonatomic) NSMutableSet *selectedLayerIDs;
@property(readonly, nonatomic) NSArray *symbols;
@property(readonly, nonatomic) id currentVerticalRulerData; // MSRulerData
@property(readonly, nonatomic) id currentHorizontalRulerData; // MSRulerData
@property(readonly, weak, nonatomic) NSArray *artboards;
@property(weak, nonatomic) id currentArtboard; // MSArtboardGroup
@property(readonly, nonatomic) id currentRoot; // MSLayerGroup<MSRootLayer>
@property(readonly, nonatomic) NSArray *exportableLayers;
@property(readonly, nonatomic) NSUInteger exportableLayersCount;
@property(readonly, nonatomic) CGRect rect;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;

+ (id <TurboCoreMSPage>)page;
+ (Class)immutableClass;
+ (BOOL)allowsFaulting;
- (void)syncPropertiesFromObject:(id)object;
- (BOOL)propertiesAreEqual:(id)props;
- (void)copyPropertiesToObject:(id)object options:(unsigned long long)options;
- (void)setAsParentOnChildren;
- (void)initializeUnsetObjectPropertiesWithDefaults;
- (BOOL)hasDefaultValues;
- (NSString*)displayName;
- (unsigned long long)displayType;

- (void)performInitEmptyObject;
- (void)performInitWithImmutableModelObject:(id)object;
- (void)objectDidInit;
- (void)duplicate:(id)arg1;

//- (void)enumerateChildProperties:(CDUnknownBlockType)arg1;
//- (void)enumerateProperties:(CDUnknownBlockType)arg1;
//+ (void)enumerateExportableLayersWithPage:(id)arg1 block:(CDUnknownBlockType)arg2;

- (void)setIsLocked:(BOOL)locked;
- (BOOL)isLocked;
- (void)setIsVisible:(BOOL)visible;
- (BOOL)isVisible;

- (CGPoint)originForNewArtboard;
- (BOOL)hasClickThrough;
- (BOOL)limitsSelectionToBounds;
- (BOOL)containsPoint:(CGPoint)point zoomValue:(double)zoomValue;
- (void)moveLayersToArtboards;
- (BOOL)canContainLayer:(id <TurboCoreMSLayer>)layer;

- (void)rectSizeDidChange:(id)arg1;
- (void)changeLayerExpandedTypeToAutomaticIfCollapsed;

- (id)parentRoot;
- (id <TurboCoreMSPage>)parentPage;
- (id)parentGroup;

- (id)ancestorsAndSelfTransforms;

- (BOOL)resizeToFitChildrenWithOption:(long long)option;
- (BOOL)layers:(id)layers fitOnArtboard:(id)artboard;
- (id)destinationArtboardForLayers:(id)layers artboards:(id)artboards;
- (BOOL)isLayerSelected:(id <TurboCoreMSLayer>)layer;
- (id)layersWithIDs:(id)IDs;
- (id)selectedLayers;
- (BOOL)tryToMoveLayerToArtboard:(id)artboard;
- (BOOL)addOrRemoveLayerFromArtboardIfNecessary:(id)arg1;
- (BOOL)tryToMoveLayer:(id <TurboCoreMSLayer>)layer toArtboards:(id)artboards;
- (id)symbolLayersInGroup:(id)group;
- (id)artboardForSlice:(id)slice inArtboards:(id)artboards;

- (void)refreshOverlayInRect:(CGRect)rect;
- (id)transform;
- (void)object:(id)object didChangeProperty:(id)props;
- (BOOL)canBeContainedByDocument;
- (void)clearSelectionCache;
- (void)changeSelectionBySelectingLayers:(id)layers;
// - (void)changeSelectionUsingBlock:(CDUnknownBlockType)arg1;

- (CGPoint)scrollOriginToCenterContentInViewBounds:(CGRect)bounds;
- (void)adjustRulerDataToTopLeftInViewBounds;
- (BOOL)shouldDrawSelection;
- (BOOL)canBeHovered;
- (id)cloneForDocument:(id)document;
- (BOOL)isExportableViaDragAndDrop;
- (BOOL)canCopyToLayer:(id <TurboCoreMSLayer>)layer1 beforeLayer:(id <TurboCoreMSLayer>)layer2;

- (id)previewImages;

@end

#pragma mark -

@protocol TurboCoreMSImmutablePage <NSObject>

@property(readonly, nonatomic) NSSet *selectedLayerIDs;
@property(readonly, nonatomic) NSArray *symbols;
@property(readonly, nonatomic) NSArray *artboards;
@property(readonly, nonatomic) CGRect contentBounds;
@property(readonly, nonatomic) id webExporterBackgoundColor; // MSImmutableColor
@property(readonly, copy, nonatomic) id grid; // MSImmutableSimpleGrid
@property(readonly, copy, nonatomic) id layout; // MSImmutableLayoutGrid
@property(readonly, copy, nonatomic) id horizontalRulerData; // MSImmutableRulerData
@property(readonly, copy, nonatomic) id verticalRulerData; // MSImmutableRulerData
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;

+ (NSUInteger)traits;
+ (id)defaultName;

- (CGPoint)rulerBase;

// MSExporter
- (id)exporterForWebOnPage:(id)page document:(id)document scale:(double)scale;
- (BOOL)shouldDiffSublayersForDifferingLayer:(id)arg1;
- (NSUInteger)transparencyLayerUseRectCondition;
- (BOOL)shouldSkipDrawingInContext:(id)context;
- (BOOL)shouldRenderInTransparencyLayer;
//- (void)prepareDrawingInContext:(id)arg1 inBlock:(CDUnknownBlockType)arg2;

- (id)svgStyle:(id)arg1;
- (BOOL)shouldIncludeInSVGExport:(id)arg1;

- (void)appendBaseTranslation:(id)arg1 exporter:(id)exporter;
- (CGPoint)layerOffsetWithExporter:(id)exporter;

@end

#pragma mark -

@protocol TurboCoreMSContentDrawViewController <NSObject> // NSViewController

@property(nonatomic) NSView <TurboCoreMSContentDrawView> *contentDrawView;
@property(nonatomic) NSView *rulerCornerView;
@property(nonatomic) NSView *verticalRuler; // MSRulerView
@property(nonatomic) NSView *horizontalRuler; // MSRulerView

@property(weak, nonatomic) id <TurboCoreMSDocument> document;
@property(weak, nonatomic) NSLayoutConstraint *rulerHeightConstraint;
@property(weak, nonatomic) NSLayoutConstraint *rulerWidthConstraint;
@property(nonatomic) id flashController; // MSFlashController
@property(nonatomic) CGFloat zoomValue;
@property(nonatomic) CGPoint scrollOrigin;

- (void)awakeFromNib;
- (void)changeToPage:(id)page;

- (void)currentArtboardDidChange;

@end

#pragma mark-

@protocol TurboCoreMSContentDrawView <NSObject> // NSView

@property(weak, nonatomic) id delegate; // MSContentDrawViewDelegate
@property(weak, nonatomic) id <TurboCoreMSDocument> document;
@property(weak, nonatomic) NSView *verticalRuler; // MSRulerView
@property(weak, nonatomic) NSView *horizontalRuler; // MSRulerView
@property(weak, nonatomic) id <TurboCoreMSLayer> hoveredLayer;
@property(nonatomic) id tiledLayerPile; // MSTiledLayerPile

@property(nonatomic) BOOL isMagnifying;
@property(nonatomic) BOOL redrawPending;
@property(nonatomic) BOOL haveStoredMostRecentFullScaleScrollOrigin;
@property(nonatomic) BOOL shouldHideOverlayControls;

@property(nonatomic) CGPoint mostRecentFullScaleScrollOrigin;
@property(nonatomic) CGPoint scalingCenterInViewCoordinates;
@property(nonatomic) CGRect overlayDirtyRect;
@property(nonatomic) CGRect scrollOriginRelativeContentRedrawRect;
@property(nonatomic) CGPoint scrollOrigin;
@property(nonatomic) CGFloat zoomValue;

@property(nonatomic) id viewPort; // MSViewPort
@property(nonatomic) id <TurboCoreMSImmutablePage> previouslyRenderedPage;
@property(nonatomic) unsigned long long previouslyRenderedColorSpace;
@property(nonatomic) NSEvent *lastEvent;
@property(readonly, nonatomic) id zoomTool; // MSZoomTool
@property(nonatomic) id cacheManager; // MSCacheManager
@property(nonatomic) id <TurboCoreMSEventHandlerManager> eventHandlerManager;

@property(readonly, nonatomic) id driver; // MSRenderingDriver
@property(nonatomic) id normalDriver; // MSRenderingDriver
@property(nonatomic) id debugDriver; // MSRenderingDriver
@property(nonatomic) id performanceMonitor; // MSRenderMonitor
@property(nonatomic) id pendingMonitor; // MSRenderMonitor

- (id <TurboCoreMSContentDrawView>)initWithFrame:(CGRect)frame;
- (id <TurboCoreMSContentDrawView>)initWithCoder:(NSCoder*)coder;

- (void)initDrivers;
- (BOOL)useDebugDriver;

- (void)prepare;

- (id)pages;
- (id)currentPage;
- (id)contentDrawView;
- (NSArray*)selectedLayers;

- (CGRect)visibleContentRect;
- (CGPoint)centerForScalingInAbsoluteCoordinates;
- (CGPoint)viewCenterInAbsoluteCoordinatesForViewPort:(id)viewPort;
- (void)animateScrollOriginToPoint:(CGPoint)point;
- (void)scrollTilesBy:(CGPoint)point;
- (void)scrollToScrollOrigin:(CGPoint)point;
- (void)placeOriginInTopLeft;
- (void)centerDocumentAndPlaceScrollOriginInTopLeft;
- (void)centerInBounds;
- (CGPoint)mouseInView;
- (BOOL)isPointOutsideCanvas:(CGPoint)point;
- (void)centerSelectionInVisibleArea;
- (void)centerLayersInCanvas;
- (void)centerRect:(CGRect)rect animated:(BOOL)animated;
- (void)centerRect:(CGRect)rect;

- (CGPoint)zoomPoint:(CGPoint)point;
- (CGSize)convertSizeToPage:(CGSize)size;
- (CGPoint)convertPointFromPage:(CGPoint)point;
- (CGPoint)convertPoint:(CGPoint)point toLayer:(id <TurboCoreMSLayer>)layer;

- (void)zoomIn;
- (void)zoomOut;
- (void)setZoomValueCenteredInCanvas:(CGFloat)zoomValue;
- (void)scaleTilesBy:(double)arg1;
- (void)scaleTilesBy:(double)arg1 withScalingCenterInViewCoordinates:(CGPoint)coordinates;
- (void)zoomToActualSizeAnimated:(BOOL)animated;
- (void)zoomToFitRect:(CGRect)rect;
- (void)animateToZoom:(CGFloat)zoomValue;
- (void)animateToZoom:(CGFloat)zoomValue scalingCenteredOnAbsoluteCoordinates:(CGPoint)coordinates;
- (void)endZoomToolMode;

- (void)tile;
- (void)reloadAllTiles;
- (void)redrawAllTiles;
- (void)redrawTiles;
- (void)redrawTileContentIfOpportune;
- (void)refreshOverlay;
- (void)refreshOverlayInViewRect:(CGRect)rect;
- (void)refreshOverlayInRect:(CGRect)rect;
- (void)scheduleRedraw;
- (void)performOverlayRefreshInViewRect:(CGRect)rect forPage:(id)page;
- (CGRect)transformRectToViewCoords:(CGRect)rect;

- (void)beginHandToolMode;
- (void)endHandToolMode;
- (void)handToolMouseUp;
- (void)handToolMouseDragged:(id)arg1;
- (void)handToolMouseDown:(id)arg1;

- (void)enableLayerBackedDrawing;
- (BOOL)canHighlightLayer:(id)arg1;

- (void)refreshOverlayAfterSettingsChange;
- (void)refreshEverythingAfterSettingsChange;

- (void)windowDidResize:(id)arg1;
- (void)pixelGridDidChange;
- (void)pageDidChange:(id)arg1;
- (void)visualSettingChanged:(id)arg1;
- (void)scrollWheelScroll:(NSEvent*)event;
- (void)scrollWheel:(NSEvent*)event;
- (void)mouseDown:(NSEvent*)event;
- (void)mouseUp:(NSEvent*)event;
- (void)mouseMoved:(NSEvent*)event;
- (void)mouseDragged:(NSEvent*)event;
- (void)mouseExited:(NSEvent*)event;
- (void)mouseEntered:(NSEvent*)event;
- (void)keyUp:(NSEvent*)event;
- (void)keyDown:(NSEvent*)event;
- (BOOL)performActionWithIdentifier:(id)arg1;

@end

#pragma mark-

@protocol TurboCoreAppController <NSObject, NSApplicationDelegate, NSWindowDelegate>

@property(nonatomic) id <TurboCoreMSPersistentAssetCollection> globalAssets;

@end

#pragma mark -

@protocol TurboCoreMSEventHandlerManager <NSObject>

@property(readonly, nonatomic) NSUndoManager *undoManager;
@property(nonatomic) id normalHandler; // MSNormalEventHandler
@property(nonatomic) id currentHandler; // MSEventHandler
@property(nonatomic) __weak id <TurboCoreMSDocument> document;

@end

#pragma mark -

@protocol TurboCoreMSPersistentAssetCollection <NSObject>

+ (id)defaultExportPresets;
- (void)applyDefaultExportPresetsIfNeeded;

@end

#pragma mark -

@protocol TurboCoreBCPopoverContentController <NSObject>
@optional;

- (void)popoverWindowDidShow:(id <TurboCoreBCPopover>)popover;

@end

#pragma mark -

@protocol TurboCoreBCPopover <NSObject>

@property (nonatomic, weak) id <TurboCoreBCPopoverDelegate> delegate;
@property (nonatomic) NSViewController *contentViewController;

- (void)showRelativeToView:(NSView*)view preferredEdge:(NSRectEdge)edge;
- (void)close;
- (void)move;

- (NSRect)popoverWindowFrame;

@end

#pragma mark -

@protocol TurboCoreBCPopoverDelegate <NSObject>

- (void)popoverWillClose:(id <TurboCoreBCPopover>)popover;
@optional;
- (void)popoverWindowSizeDidChange:(id <TurboCoreBCPopover>)popover;
- (void)popoverWindowDidMove:(id <TurboCoreBCPopover>)popover;
- (BOOL)popoverShouldCloseWhenNewPopoverOpens:(id <TurboCoreBCPopover>)popover newPopover:(id <TurboCoreBCPopover>)newPopover;
- (BOOL)popoverShouldCauseExistingPopoversToClose:(id <TurboCoreBCPopover>)popover;

@end

#pragma mark -

@protocol TurboCoreMSLayer <NSObject>

@property(readonly, nonatomic) NSString *objectID;
@property(nonatomic) NSString *originalObjectID;

@property(copy, nonatomic) NSString *name;
@property(nonatomic) NSString *nodeName;
@property(readonly, nonatomic) NSDictionary *previewImages;

@property(nonatomic) CGPoint center;
@property(nonatomic) CGPoint origin;
@property(nonatomic) CGRect rect;
@property(nonatomic) CGPoint absolutePosition;
//@property(nonatomic) MSRect *frame;
@property(readonly, nonatomic) CGRect bounds;
@property(readonly, nonatomic) CGRect rectForSnapping;
//@property(nonatomic) MSAbsoluteRect *absoluteRect;
//@property(readonly, nonatomic) struct BCEdgePaddings influenceRectEdgePaddingsThatCascadeToContainedLayers;

@property(nonatomic) BOOL isVisible;
@property(nonatomic) BOOL isLocked;
@property(nonatomic) BOOL isFlippedVertical;
@property(nonatomic) BOOL isFlippedHorizontal;
@property(nonatomic) BOOL isHovering;
@property(readonly, nonatomic) BOOL isActive;
@property(readonly, nonatomic) BOOL isSelected;
@property(readonly, nonatomic) BOOL isExpanded;
@property(readonly, nonatomic) BOOL hasSliceIcon;
@property(readonly, nonatomic) BOOL hasHighlight;
@property(readonly, nonatomic) BOOL isLayerExportable;
@property(readonly, nonatomic) BOOL hasTransforms;
@property(readonly, nonatomic) BOOL selectedInLayerList;
@property(readonly, nonatomic) BOOL expandableInLayerList;

@property(readonly, nonatomic) BOOL canFixHeight;
@property(readonly, nonatomic) BOOL canFixWidth;
@property(readonly, nonatomic) BOOL canFixBottom;
@property(readonly, nonatomic) BOOL canFixTop;
@property(readonly, nonatomic) BOOL canFixRight;
@property(readonly, nonatomic) BOOL canFixLeft;
@property(nonatomic) BOOL hasFixedEdges;
@property(nonatomic) BOOL hasFixedHeight;
@property(nonatomic) BOOL hasFixedWidth;
@property(nonatomic) BOOL hasFixedBottom;
@property(nonatomic) BOOL hasFixedTop;
@property(nonatomic) BOOL hasFixedRight;
@property(nonatomic) BOOL hasFixedLeft;

@property(readonly, nonatomic) CGAffineTransform CGTransformForFrame;
@property(nonatomic) CGFloat userVisibleRotation;
@property(readonly, nonatomic) CGFloat rotation;
@property(readonly, nonatomic) NSSet *fontNames;
@property(readonly, nonatomic) NSSet *unavailableFontNames;
@property(readonly, nonatomic) unsigned long long filterType;
@property(readonly, nonatomic) unsigned long long displayType;

@property(copy, nonatomic) NSDictionary *userInfo;

- (id <TurboCoreMSLayer>)initWithFrame:(CGRect)frame;

+ (NSString*)defaultName;
+ (unsigned long long)traits;
+ (CGFloat)userVisibleRotationForRotation:(CGFloat)rotation;
+ (void)alignLayers:(NSArray*)layers toValue:(double)value forKey:(NSString*)key;
+ (void)alignLayers:(NSArray*)layers withMode:(unsigned long long)mode toKey:(NSString*)key pixelFit:(BOOL)pixelFit;
+ (CGRect)alignmentRectForLayers:(NSArray*)layers;

- (void)setName:(NSString*)name;
- (NSString*)displayName;
- (NSArray*)namesOfAllLayersInContainer:(id)container;
- (void)makeNameUniqueInRoot:(id)arg1 withOptions:(long long)options;
- (void)makeNameUniqueWithOptions:(long long)options;
- (BOOL)validateNodeName:(NSString**)name error:(NSError**)error;

- (id)valueForUndefinedKey:(id)key;

- (void)setAsParentOnChildren;
- (id)allSymbolInstancesInChildren;
- (id)layerWithID:(id)ID;
- (void)setValue:(id)value forUndefinedKey:(NSString*)key;
- (void)setNilValueForKey:(NSString*)key;

- (id)transform;
- (BOOL)canBeTransformed;
- (void)concatAncestorsAndSelfTransforms;
- (void)multiplyBy:(CGFloat)factor;
- (id)transformForRect:(CGRect)rect;
- (CGRect)frameForTransforms;

- (CGPoint)convertPointFromRuler:(CGPoint)point;
- (CGPoint)convertPointToRuler:(CGPoint)point;
- (CGRect)convertRectToAbsoluteCoordinates:(CGRect)rect;
- (CGPoint)convertPoint:(CGPoint)point fromLayer:(id <TurboCoreMSLayer>)layer;
- (CGPoint)convertPoint:(CGPoint)point toLayer:(id <TurboCoreMSLayer>)layer;

- (BOOL)containsPoint:(CGPoint)point zoomValue:(CGFloat)zoomValue;
- (BOOL)hitTestRect:(CGRect)rect options:(unsigned long long)options;
- (BOOL)isLayerAtIndex:(NSUInteger)index maskedAtPoint:(CGPoint)point zoomValue:(CGFloat)zoomValue;
- (id)selectionHitTest:(CGPoint)point options:(unsigned long long)options zoomValue:(CGFloat)options resultIndex:(NSUInteger*)resultIndex;
- (id)selectableLayersWithOptions:(unsigned long long)options;
- (BOOL)limitsSelectionToBounds;
- (BOOL)isOpenForSelectionWithOptions:(unsigned long long)options;
- (BOOL)isSelectableOnCanvasWithOptions:(unsigned long long)options;
- (CGRect)distanceRectangleToItem:(id)item axis:(unsigned long long)arg2;

- (BOOL)isRectIntegral;
- (void)makeRectIntegral;
- (void)makeOriginIntegral;

- (BOOL)canBeHidden;
- (BOOL)canBeHovered;
- (BOOL)isLine;
- (BOOL)hasEnabledBackgroundBlur;
- (BOOL)shouldDrawSelection;
- (BOOL)canSmartRotate;
- (BOOL)isOpen;
- (BOOL)shouldFlattenAfterRotate;
- (BOOL)supportsInnerOuterBorders;
- (BOOL)canSplitPaths;
- (BOOL)canConvertToOutlines;
- (BOOL)isMasked;
- (long long)cornerRectType;
- (unsigned long long)traits;
- (BOOL)canSnapSizeToLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)canSnapToLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)canCopyToLayer:(id <TurboCoreMSLayer>)layer beforeLayer:(id <TurboCoreMSLayer>)beforeLayer;
- (BOOL)canMoveToLayer:(id <TurboCoreMSLayer>)layer beforeLayer:(id <TurboCoreMSLayer>)beforeLayer;

- (id)ancestorsAndSelfTransforms;
- (id)ancestorsAndSelf;
- (id)ancestors;
- (id)parentSymbol;
- (id)parentArtboard;
- (id)parentRoot;
- (id)parentPage;
- (void)removeFromParent;

- (id)bezierPath;
- (id)bezierPathWithTransforms;
- (id)bezierPathForHover;
- (id)colorForHover;
- (id)layersByConvertingToOutlines;
- (Class)layerSnapperObjectClass;

- (void)drawHoverWithZoom:(double)arg1 cache:(id)arg2;

- (void)refreshOverlay;
- (void)refreshOverlayInRect:(CGRect)rect;
- (void)refreshOverlayWithAbsoluteMargins:(CGSize)size;
- (CGRect)transformRectToParentCoordinates:(CGRect)rect;

- (CGRect)absoluteInfluenceRect;
- (CGRect)overlayInfluenceRectForBounds;
- (CGRect)influenceRectForBounds;
- (CGRect)overlayInfluenceRectForFrame;
- (CGRect)influenceRectForFrame;
- (CGSize)calculateMinimumSize;

- (void)layerDidResizeFromRect:(CGRect)rect corner:(long long)corner;
- (void)layerDidEndResize;
- (void)layerWillStartResize;

- (void)select:(BOOL)arg1 byExtendingSelection:(BOOL)arg2 showSelection:(BOOL)arg3;
- (void)select:(BOOL)arg1 byExtendingSelection:(BOOL)arg2;
- (id)duplicate;
- (void)copyToLayer:(id <TurboCoreMSLayer>)layer beforeLayer:(id <TurboCoreMSLayer>)beforeLayer;
- (void)moveToLayer:(id <TurboCoreMSLayer>)layer beforeLayer:(id <TurboCoreMSLayer>)beforeLayer;

- (id)unselectedPreviewImage;
- (id)selectedPreviewImage;

- (id <TurboCoreMSLayer>)lastLayer;
- (id <TurboCoreMSLayer>)firstLayer;
- (NSUInteger)indexOfLayer:(id <TurboCoreMSLayer>)layer;
- (id <TurboCoreMSLayer>)layerAtIndex:(NSUInteger)index;
- (NSArray*)children;
- (NSArray*)containedLayers;
- (NSUInteger)containedLayersCount;
- (BOOL)containsMultipleLayers;
- (BOOL)containsOneLayer;
- (BOOL)containsLayers;
- (BOOL)containsNoOrOneLayers;
- (BOOL)canBeContainedByDocument;
- (BOOL)canBeContainedByGroup;
- (BOOL)canContainLayer:(id <TurboCoreMSLayer>)layer;
- (BOOL)isPartOfClippingMask;
- (BOOL)hasClippingMask;

- (id <TurboCoreMSLayer>)closestClippingLayer;
- (id)candidatesForMasking;
- (void)resetConstraints;
- (void)setFixed:(BOOL)isFixed forEdge:(unsigned long long)edge;
- (BOOL)hasFixedEdge:(unsigned long long)edge;
- (void)applyOverride:(id)arg1 toPoint:(id)arg2;
- (void)applyOverrides:(id)arg1;

- (long long)layoutDirection;
- (id)overridePointsWithParent:(id)arg1;
- (id)overridePoints;
- (id)CSSAttributes;
- (id)CSSRotationString;
- (id)CSSAttributeString;


@end

#pragma mark -

@protocol TurboCoreMSTextLayer <TurboCoreMSLayer>

@property(copy, nonatomic) NSArray *baselineOffsetsValue;
@property(nonatomic) NSNumber *defaultLineHeightValue;
@property(weak, nonatomic) id editingDelegate; // MSTextLayerEditingDelegate
@property(nonatomic) BOOL isEditingText;
@property(nonatomic) CGRect previousRectCache;
@property(copy, nonatomic) NSString *stringValue;
@property(copy, nonatomic) NSAttributedString *attributedStringValue;
@property(copy, nonatomic) NSDictionary *styleAttributes;
@property(copy, nonatomic) id <TurboCoreMSColor> textColor;
@property(nonatomic) double lineHeight;
@property(nonatomic) NSNumber *characterSpacing;
@property(nonatomic) NSString *fontPostscriptName;
@property(nonatomic) CGFloat fontSize;
@property(nonatomic) long long verticalAlignment;
@property(nonatomic) unsigned long long textAlignment;
@property(readonly, nonatomic) NSBezierPath *bezierPath;

- (id)initWithFrame:(CGRect)frame attributes:(id)arg2 documentColorSpace:(NSColorSpace*)colorSpace type:(long long)type;
- (id)initWithAttributedString:(NSAttributedString*)attributedString documentColorSpace:(NSColorSpace*)colorSpace maxWidth:(CGFloat)maxWidth;
- (id)initWithFrame:(CGRect)frame;

+ (void)setTextAlignment:(unsigned long long)alignment forLayers:(NSArray*)layers;
+ (BOOL)canSetTextAlignmentForLayers:(NSArray*)layers;
+ (void)setTextVerticalAlignment:(long long)alignment forLayers:(NSArray*)layers;
+ (BOOL)canSetTextVerticalAlignmentForLayers:(NSArray*)layers;

- (BOOL)canScale;
- (BOOL)canBeTransformed;
- (BOOL)constrainProportions;
- (BOOL)isEmpty;
- (BOOL)canConvertToOutlines;
- (BOOL)supportsInnerOuterBorders;
- (BOOL)canFixHeight;

- (CGFloat)baseLineHeight;
- (CGFloat)baselineAdjustmentForLayoutManager:(id)layoutManager;
- (CGFloat)defaultLineHeight:(id)arg1;
- (void)setFont:(NSFont*)font;
- (NSFont*)font;
- (void)setLeading:(CGFloat)leading;
- (CGFloat)leading;
- (void)setKerning:(float)kerning;
- (float)kerning;
- (void)setTextBehaviour:(long long)behaviour;
- (void)setTextBehaviour:(long long)behaviour mayAdjustFrame:(BOOL)flag;
- (void)setStyle:(id)style;
- (id)bezierPathFromGlyphsInBounds;
- (id)bezierPathFromGlyphsInFrame;
- (id)bezierPathWithTransforms;
- (CGPoint)drawingPointForText;
- (CGFloat)startingPositionOnPath:(id)path;
- (id)shapeToUseForTextOnPath;
- (id)paragraphStyle;
- (long long)layoutDirection;
- (long long)cornerRectType;
- (unsigned long long)resizingConstraint;

- (void)setTextTransform:(unsigned long long)transform range:(NSRange)range;
- (void)multiplyBy:(CGFloat)factor;
- (void)adjustFrameToFit;

- (id)attributeForKey:(NSString*)key;
- (void)addAttribute:(id)attribute value:(id)value;
- (void)addAttributes:(id)attributes forRange:(NSRange)range;
- (void)setAttributes:(id)attributes forRange:(NSRange)range;
- (void)addAttribute:(id)attribute value:(id)value forRange:(NSRange)range;
- (void)syncTextStyleAttributes;
- (void)setRectAccountingForClipped:(CGRect)rect;

- (void)makeLowercase:(id)arg1;
- (void)makeUppercase:(id)arg1;
- (id)layersByConvertingToOutlines;
- (Class)layerSnapperObjectClass;
- (void)finishEditing;
- (void)refreshOverlay;
- (void)updateNameFromStorage;
- (void)replaceMissingFontsIfNecessary;

- (id)unselectedPreviewImage;
- (id)selectedPreviewImage;
- (id)PDFPreview;
- (BOOL)shouldStorePDFPreviews;
- (void)writeStyleToPasteboard:(id)arg1;

@end

#pragma mark -

@protocol TurboCoreMSColor <NSObject>

@property(readonly, nonatomic) double red;
@property(readonly, nonatomic) double green;
@property(readonly, nonatomic) double blue;
@property(readonly, nonatomic) double alpha;
@property(readonly, nonatomic) double brightness;
@property(readonly, nonatomic) double saturation;
@property(readonly, nonatomic) double hue;

+ (id <TurboCoreMSColor>)colorWithNSColor:(NSColor*)color;
+ (id <TurboCoreMSColor>)colorWithRed:(double)red green:(double)green blue:(double)blue alpha:(double)alpha;
+ (id <TurboCoreMSColor>)colorWithHue:(double)hue saturation:(double)sat brightness:(double)bri alpha:(double)alpha;
+ (id <TurboCoreMSColor>)blackColor;
+ (id <TurboCoreMSColor>)whiteColor;

- (NSColor*)NSColorWithColorSpace:(NSColorSpace*)colorSpace;
- (NSColor*)HSBColor;

@end

#pragma mark -

@protocol TurboCoreMSColorInspectorDelegate <NSObject>

- (void)colorInspector:(id <TurboCoreMSColorInspector>)colorInspector didChangeToColor:(id <TurboCoreMSColor>)color;

@optional
- (void)colorInspectorDidChange:(id <TurboCoreMSColorInspector>)colorInspector;
- (void)colorInspectorWillClose:(id <TurboCoreMSColorInspector>)colorInspector;
- (void)inspectorDidChangeType:(id <TurboCoreMSColorInspector>)colorInspector;

@end

#pragma mark -

@protocol TurboCoreMSColorInspector <NSObject>

@property (nonatomic) NSView <TurboCoreMSStackView> *stackView;
@property (nonatomic) NSView <TurboCoreMSModePickerView> *fillColorTypePicker;
@property (weak, nonatomic) id <TurboCoreMSColorInspectorDelegate> delegate;

- (id)initWithSender:(id)sender
			document:(id <TurboCoreMSDocument>)document
	  handlerManager:(id)arg3
		globalAssets:(id)arg4;

+ (id)presentColorInspectorPopoverForViewController:(NSViewController*)viewController
								inspectorController:(id)inspectorController
									 relativeToView:(NSView*)view
									   initialColor:(id)color;

- (void)close;

/// 表示前に実行して、ビューを構築してください
- (void)prepareForDisplay;

/// 色の初期値を設定します
- (void)setInitialColor:(id <TurboCoreMSColor>)arg1;
- (void)setColor:(id <TurboCoreMSColor>)arg1;

/* カラーピッカー操作時には、次の順でメソッドが実行される
 1: カラーピッカーの色が変更される直前
 -colorDidChangeTo:
 2: カラーピッカーの色が変更される直後
 -colorChangedTo:
 3: カラーピッカーの操作直後
 -colorPickerAction:

 パレットからの適用では、 -colorDidChangeTo: のみが実行される。
 ノイズ等特殊なテクスチャの適用の際には、これが呼ばれるものの引数は nil になることもある。

 RGB/HSBモード変更の際には、-colorModeViewDidChange: が実行される。
*/

/// カラーピッカーの色が変更される直前
- (void)colorDidChangeTo:(id <TurboCoreMSColor>)color;
/// カラーピッカーの色が変更される直後
- (void)colorChangedTo:(id <TurboCoreMSColor>)color;
/// カラーピッカーの操作直後. sender = BCHSBColorPicker など
- (void)colorPickerAction:(id)sender;
/// RGB/HSBモード変更の直後 (MSAlternatingViewDidToggleNotification)
- (void)colorModeViewDidChange:(NSNotification*)notif;

- (void)adjustInspectorToColorPopoverIfNeeded:(id)arg1;
- (void)applyBackgroundArrowColor;
- (void)colorMagnifierAction:(id)arg1;
- (void)changeColor:(id)arg1;

/// 色種別のタブ（ベタ塗り、グラデーション、画像、ノイズ等）を変更
- (void)setColorTabIndex:(NSUInteger)index;
- (NSUInteger)colorTabIndex;
- (void)switchToColorTabAtIndex:(NSUInteger)index;
- (void)refreshTabbingCycle;

@end

#pragma mark -

@protocol TurboCoreMSInspectorController <NSObject>

@property(nonatomic) NSView *exportPanelContainerView; // @synthesize exportPanelContainerView=_exportPanelContainerView;
@property(nonatomic) NSView *contentContainerView; // @synthesize contentContainerView=_contentContainerView;
@property(nonatomic) NSView *alignmentView; // @synthesize alignmentView=_alignmentView;
@property(nonatomic) NSViewController *artboardInspector; // MSArtboardInspectorViewController
@property(nonatomic) NSViewController *slicesInspector; // MSSliceInspectorViewController
@property(nonatomic) NSViewController *normalInspector; // MSNormalInspector
@property(nonatomic) NSViewController *bottomExporter; // MSExportInspectorViewController
@property(nonatomic) NSViewController *currentController; // MSInspectorChildController
@property(nonatomic) BOOL exportPanelHidden;
@property(nonatomic) BOOL alignmentBarHidden;
@property(weak, nonatomic) id <TurboCoreMSDocument> document;

- (void)awakeFromNib;
- (void)prepareForDisplay;
- (void)reload;
- (void)refreshCurrentController;
- (void)reloadSharedObjectsSection;
- (void)recursivelyDismissAllPresentedViewControllersOfViewController:(id)arg1;
- (void)layoutContentView;
- (id)inspectorController;
- (id)sharedObjectsSection;
- (void)validateAlignmentButtons;

@end

#pragma mark -

@protocol TurboCoreMSModePickerView <NSObject>

@property(weak, nonatomic) id delegate; // MSModeModePickerDelegate
@property(nonatomic) long long pickerMode;

@end

#pragma mark -

@protocol TurboCoreMSColorPreviewButton <NSObject>

@property(copy, nonatomic) NSColor *color;

@end

#pragma mark -

@protocol TurboCoreMSStackView <NSObject>

@property(retain, nonatomic) NSColor *backgroundColor; // @synthesize backgroundColor=_backgroundColor;
@property(nonatomic) double minimumHeight; // @synthesize minimumHeight=_minimumHeight;
@property(nonatomic) long long maximumHeight; // @synthesize maximumHeight=_maximumHeight;
@property(nonatomic) BOOL autoupdatesMaximumHeight; // @synthesize autoupdatesMaximumHeight=_autoupdatesMaximumHeight;

- (void)adjustHeight:(unsigned long long)arg1 hasScrollViews:(BOOL)flag;
- (unsigned long long)doStack;
- (long long)totalRequiredHeight;
- (BOOL)adjustScrollViewsToFitMaximumHeight;
- (NSRect)adjustScroll:(NSRect)rect;
- (double)refreshMaximumHeightFromSubviews;
- (void)stack:(id)arg1;

@end

#pragma mark -

@protocol TurboCoreMSInspectorStackView <NSObject>

@property (nonatomic, strong) NSArray *sectionViewControllers;
- (void)reloadWithViewControllers:(NSArray *)controllers;

@end

#pragma mark -

@protocol TurboCoreMSLayerSection <NSObject> // NSViewController

@property(copy, nonatomic) NSArray *layers;

- (id <TurboCoreMSLayerSection>)initWithLayer:(id <TurboCoreMSLayer>)layer;
- (NSArray*)views;

@end

#pragma mark -

@protocol TurboCoreMSTextLayerSection <TurboCoreMSLayerSection>

@property(nonatomic) NSSegmentedControl *verticalAlignmentButton;
@property(nonatomic) NSSegmentedControl *alignmentButton;

@property(nonatomic) NSView *basicView;
@property(nonatomic) NSView *missingFontsView;

- (BOOL)hasMissingFonts;
- (BOOL)hasMoreThanOneMissingFont;

@end

#pragma mark -

@protocol TurboCoreBCSideBarViewController <NSObject>

@property(nonatomic, weak) NSSplitView *splitView; // BCSplitView
@property(nonatomic, weak) NSButton *togglePageListButton;
@property(nonatomic, weak) NSSearchField *filterStringTextField;
@property(nonatomic, weak) NSPopUpButton *pagePopup;
@property(nonatomic, weak) NSTextField *currentPageLabel;
@property(nonatomic) BOOL userUpdatedPageHeight;
@property(nonatomic) id layerListViewController; // BCOutlineViewController
@property(nonatomic) NSView *layerListContainer;
@property(nonatomic) id layerListDataController; // BCOutlineViewDataController
@property(nonatomic) NSInteger pageCount;
@property(nonatomic) CGFloat currentPageHeight;
@property(nonatomic) id pageListViewController; // BCPageListViewController
@property(nonatomic) NSView *pageListContainer;
@property(nonatomic) NSView *pageCreationView;
@property(nonatomic) id pageListDataController; // BCOutlineViewDataController
@property(nonatomic) id filter; // BCFilterInfo
@property(nonatomic, weak) id <TurboCoreBCSideBarViewControllerDelegate> delegate;

@property(readonly, nonatomic) BOOL isPageListCollapsed;
@property(readonly, nonatomic) id <TurboCoreBCOutlineViewNode> currentPage;

- (id)initWithPageListDataSource:(id)pageListDataSource
						delegate:(id)delegate1
			 layerListDataSource:(id)layerListDataSource
						delegate:(id)delegate2;
- (void)awakeFromNib;

- (void)onTogglePageList:(id)arg1;
- (void)showPageView;
- (void)hidePageView;
- (void)findLayer:(id)arg1;
- (void)renamePage;
- (void)renameLayerAfterNextLayerListRefresh;
- (void)renameLayer;
- (void)checkPageListHeight;
- (void)refreshPagePopup;
- (void)pagePopupChanged:(id)arg1;
- (void)refreshPageLabel;
- (void)embedView:(id)arg1 inView:(id)arg2;

// NSSplitViewDelegate

- (void)splitViewDidResizeSubviews:(NSNotification *)notification;
- (CGFloat)splitView:(NSSplitView *)splitView constrainSplitPosition:(CGFloat)proposedPosition ofSubviewAt:(NSInteger)dividerIndex;
- (CGFloat)splitView:(NSSplitView *)splitView constrainMinCoordinate:(CGFloat)proposedMinimumPosition ofSubviewAt:(NSInteger)dividerIndex;
- (CGFloat)splitView:(NSSplitView *)splitView constrainMaxCoordinate:(CGFloat)proposedMaximumPosition ofSubviewAt:(NSInteger)dividerIndex;
- (BOOL)splitView:(NSSplitView *)splitView canCollapseSubview:(NSView *)subview;

@end

#pragma mark -

@protocol TurboCoreBCSideBarViewControllerDelegate <NSObject>

@property(nonatomic) double pageListHeight;

@end

#pragma mark -

@protocol TurboCoreBCOutlineViewNode <NSObject>

@end

#endif /* SketchRuntime_h */
